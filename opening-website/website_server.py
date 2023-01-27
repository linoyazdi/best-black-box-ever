from flask import Flask, request
import scapy.all as scapy
from threading import Thread
import time

app = Flask("test")
MESSAGE = "hello"


def send_packet(dst_ip, dst_port, src_port):
    pkt = scapy.IP(dst=dst_ip) / scapy.TCP(sport=int(src_port), dport=int(dst_port))  / scapy.Raw(MESSAGE) 
    pkt.show()
    print(pkt.build())
    time.sleep(1)
    scapy.sendp(pkt, iface='wlan0')


@app.route("/")
def index():
    dst_ip = request.environ['REMOTE_ADDR']
    dst_port = request.environ['REMOTE_PORT']
    src_port = request.environ['SERVER_PORT']
    print(dst_ip, dst_port, src_port)
    t = Thread(target=lambda: send_packet(dst_ip, dst_port, src_port))
    t.start()
    return "yo"

app.run(host='0.0.0.0', port=3030)
