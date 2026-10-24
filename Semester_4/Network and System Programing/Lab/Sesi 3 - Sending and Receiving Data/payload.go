package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
)

const (
	BinaryType uint8 = iota + 1
	StringType
)

type Payload interface {
	io.WriterTo
	io.ReaderFrom
	Bytes() []byte
	String() string
}

type Binary []byte

func (m Binary) Bytes() []byte {
	return m
}

func (m Binary) String() string {
	return string(m)
}

func (m Binary) WriteTo(w io.Writer) (int64, error) {
	if err := binary.Write(w, binary.BigEndian, BinaryType); err != nil {
		return 0, err
	}

	if err := binary.Write(w, binary.BigEndian, uint32(len(m))); err != nil {
		return 0, err
	}

	n, err := w.Write(m)
	return int64(n + 5), err
}

func (m *Binary) ReadFrom(r io.Reader) (int64, error) {
	var typ uint8
	if err := binary.Read(r, binary.BigEndian, &typ); err != nil {
		return 0, err
	}

	var size uint32
	if err := binary.Read(r, binary.BigEndian, &size); err != nil {
		return 0, err
	}

	*m = make([]byte, size)
	n, err := io.ReadFull(r, *m)
	return int64(n + 5), err
}

type String string

func (m String) Bytes() []byte {
	return []byte(m)
}

func (m String) String() string {
	return string(m)
}

func (m String) WriteTo(w io.Writer) (int64, error) {
	if err := binary.Write(w, binary.BigEndian, StringType); err != nil {
		return 0, err
	}

	data := []byte(m)

	if err := binary.Write(w, binary.BigEndian, uint32(len(data))); err != nil {
		return 0, err
	}

	n, err := w.Write(data)
	return int64(n + 5), err
}

func (m *String) ReadFrom(r io.Reader) (int64, error) {
	var typ uint8
	if err := binary.Read(r, binary.BigEndian, &typ); err != nil {
		return 0, err
	}

	var size uint32
	if err := binary.Read(r, binary.BigEndian, &size); err != nil {
		return 0, err
	}

	data := make([]byte, size)
	n, err := io.ReadFull(r, data)
	*m = String(data)

	return int64(n + 5), err
}

func decode(r io.Reader) (Payload, error) {
	var typ uint8
	if err := binary.Read(r, binary.BigEndian, &typ); err != nil {
		return nil, err
	}

	var payload Payload
	switch typ {
	case BinaryType:
		payload = new(Binary)
	case StringType:
		payload = new(String)
	default:
		return nil, fmt.Errorf("invalid type")
	}

	_, err := payload.ReadFrom(io.MultiReader(bytes.NewReader([]byte{typ}), r))
	return payload, err
}
