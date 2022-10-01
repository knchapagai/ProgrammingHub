import socket

hostnm = socket.gethostname()
ipaddr = socket.gethostbyname(hostnm)

print("\nIP Address is:", ipaddr)
