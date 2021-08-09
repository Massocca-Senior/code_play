import time
import socket

mcast_group_ip = '239.0.0.2'
mcast_group_port =  9000

def sender():
    send_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    while True:
        message = "this message send via mcast !" + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) + "\n"
        send_sock.sendto(message.encode(), (mcast_group_ip, mcast_group_port))
        print(f'{time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}: message send finish')
        time.sleep(2)

if __name__ == "__main__":
    sender()