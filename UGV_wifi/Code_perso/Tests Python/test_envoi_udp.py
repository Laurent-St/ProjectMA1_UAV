import socket
from time import sleep

#UDP_IP = "2a02:2788:1014:131a:87c:e26:38f6:ca5e"
"""
UDP_IP="192.168.0.22"
UDP_PORT = 333
message = "test"
"""
#TARGET_IP="192.168.0.22"
#TARGET_IP="192.168.4.1"
TARGET_IP="192.168.0.22"
TARGET_PORT=333
#TARGET_PORT=8266
message = "test"

print ("UDP target IP:", TARGET_IP)
print ("UDP target port:", TARGET_PORT)
print ("message:", message)

sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
#sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

#SELF_IP="192.168.0.13"
SELF_IP="0.0.0.0"
SELF_PORT=444
#SELF_IP="192.168.0.24"

#sock.bind((SELF_IP,UDP_PORT))
sock.bind((SELF_IP,SELF_PORT))

#while True:
#sock.bind((UDP_IP,UDP_PORT))

"""
while True:
    data,addr=sock.recvfrom(1024)
    print("Received message:",data)
    message=input("message")
    #sock.sendto(bytes(message,"utf-8"),(UDP_IP,UDP_PORT))
    sock.sendto(bytes(message,"utf-8"),(TARGET_IP,TARGET_PORT))
"""

while True:
    sleep(1)
    sock.sendto(bytes(message,"utf-8"),(TARGET_IP,TARGET_PORT))
