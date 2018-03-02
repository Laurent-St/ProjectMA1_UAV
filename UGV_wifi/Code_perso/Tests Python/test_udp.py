import socket

#UDP_IP = "192.168.0.24"
#UDP_PORT = 5005

UDP_IP="0.0.0.0"
#UDP_IP="192.168.0.123"
UDP_PORT=444

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP

sock.bind((UDP_IP, UDP_PORT))

while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print ("received message:", data)
