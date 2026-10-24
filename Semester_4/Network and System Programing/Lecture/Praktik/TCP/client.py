import socket

socket_ctx = socket.socekt(socket.AF_INET, socket.SOCK_STREAM)

target = "127.0.0.1"
port = 9999

socket_ctx.connect((target, port))
fn = input("Input Filename > ")

# Baca Filename
f = open(fn, "rb")

while True:
    x = f.read()
    if x != "":
        print(x)
    else:
        break