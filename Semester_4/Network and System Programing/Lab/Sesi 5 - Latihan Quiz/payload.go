package main

import (
	"bytes"
	"encoding/binary"
	"io"
)

// iota + 1 bikin konstanta auto-increment mulai dari 1
// BinaryType = 1, StringType = 2
// dipakai sebagai "tanda" di awal setiap data yang dikirim lewat jaringan
// supaya penerima tau harus decode sebagai Binary atau String
const (
	BinaryType uint8 = iota + 1
	StringType
)

// Payload adalah interface — kontrak yang harus dipenuhi oleh Binary dan String
// siapapun yang punya keempat method ini dianggap sebagai Payload
// io.WriterTo  => harus punya WriteTo(w io.Writer)
// io.ReaderFrom => harus punya ReadFrom(r io.Reader)
type Payload interface {
	io.WriterTo
	io.ReaderFrom
	Bytes() []byte
	String() string
}

// Binary adalah tipe data untuk payload berupa raw bytes ([]byte)
type Binary []byte

// Bytes() return isi Binary sebagai []byte
func (m Binary) Bytes() []byte {
	return m
}

// String() convert isi Binary ke string biasa
func (m Binary) String() string {
	return string(m)
}

// WriteTo nulis Binary ke koneksi/writer dengan format:
// [1 byte: BinaryType] [4 byte: panjang data] [N byte: isi data]
func (m Binary) WriteTo(w io.Writer) (int64, error) {
	// tulis 1 byte pertama: tipe payload (BinaryType = 1)
	// BigEndian = byte paling penting ditulis duluan (network standard)
	err := binary.Write(w, binary.BigEndian, BinaryType)
	if err != nil {
		return 0, err
	}

	// tulis 4 byte berikutnya: panjang data (uint32)
	// supaya penerima tau berapa byte yang harus dibaca setelah ini
	err = binary.Write(w, binary.BigEndian, uint32(len(m)))
	if err != nil {
		return 0, err
	}

	// tulis isi datanya, return berapa byte yang berhasil ditulis
	n, err := w.Write(m)
	if err != nil {
		return 0, err
	}

	// +5 karena kita juga nulis 1 byte (type) + 4 byte (size) = 5 byte header
	return int64(n + 5), err
}

// ReadFrom baca Binary dari koneksi/reader
// pointer receiver (*Binary) supaya bisa modifikasi nilai Binary dari luar
func (m *Binary) ReadFrom(r io.Reader) (int64, error) {
	// baca 1 byte pertama untuk dapat tipe payload-nya
	var typ uint8
	err := binary.Read(r, binary.BigEndian, &typ)
	if err != nil {
		return 0, err
	}

	// baca 4 byte berikutnya untuk dapat ukuran data
	var size uint32
	err = binary.Read(r, binary.BigEndian, &size)
	if err != nil {
		return 0, err
	}

	// buat slice dengan ukuran yang sudah diketahui, lalu isi dari reader
	*m = make([]byte, size)
	n, err := r.Read(*m)

	return int64(n + 5), err
}

// String adalah tipe data untuk payload berupa teks (string)
type String string

// Bytes() convert String ke []byte
func (m String) Bytes() []byte {
	return []byte(m)
}

// String() return isi String sebagai string Go biasa
func (m String) String() string {
	return string(m)
}

// WriteTo nulis String ke koneksi/writer dengan format:
// [1 byte: StringType] [4 byte: panjang data] [N byte: isi data]
func (m String) WriteTo(w io.Writer) (int64, error) {
	// tulis 1 byte tipe (StringType = 2)
	err := binary.Write(w, binary.BigEndian, StringType)
	if err != nil {
		return 0, err
	}

	// convert string ke []byte supaya bisa dihitung panjangnya dan ditulis
	data := []byte(m)

	// tulis 4 byte ukuran data
	err = binary.Write(w, binary.BigEndian, uint32(len(data)))
	if err != nil {
		return 0, err
	}

	// tulis isi data, return total byte termasuk 5 byte header
	n, err := w.Write(data)
	return int64(n + 5), err
}

// ReadFrom baca String dari koneksi/reader
func (m *String) ReadFrom(r io.Reader) (int64, error) {
	// baca 1 byte tipe
	var typ uint8
	err := binary.Read(r, binary.BigEndian, &typ)
	if err != nil {
		return 0, err
	}

	// baca 4 byte ukuran
	var size uint32
	err = binary.Read(r, binary.BigEndian, &size)
	if err != nil {
		return 0, err
	}

	// buat buffer sesuai ukuran, baca dari reader ke buffer
	data := make([]byte, size)
	n, err := r.Read(data)
	if err != nil {
		return 0, err
	}

	// simpan hasil baca ke *m (mengubah nilai String dari luar)
	*m = String(data)
	return int64(n + 5), err
}

// Decode baca dari reader dan return Payload yang sudah ditentukan tipenya
// ini entry point utama untuk menerima data dari koneksi TCP
func Decode(r io.Reader) (Payload, error) {
	// baca 1 byte pertama untuk tahu tipe payload yang akan datang
	var t uint8
	err := binary.Read(r, binary.BigEndian, &t)
	if err != nil {
		return nil, err
	}

	// tentukan tipe payload berdasarkan byte yang dibaca
	var payload Payload
	switch t {
	case BinaryType:
		payload = new(Binary)
	case StringType:
		payload = new(String)
	}

	// io.MultiReader dipakai untuk "kembalikan" byte pertama yang sudah dibaca
	// karena ReadFrom() juga akan baca dari awal (termasuk byte tipe)
	// jadi kita gabungkan: bytes.NewReader([]byte{t}) + r asli
	// sehingga ReadFrom membaca: [t, ...sisa data dari r...]
	_, err = payload.ReadFrom(io.MultiReader(bytes.NewReader([]byte{t}), r))
	if err != nil {
		return nil, err
	}

	return payload, nil
}
