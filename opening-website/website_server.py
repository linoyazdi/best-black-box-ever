from flask import Flask, request, render_template
import scapy.all as scapy
from threading import Thread
import time
import argparse
from consts import KIM_POSSIBLE_SONG, RICK_ROLL
from random import randint

app = Flask("Kim's Website", static_folder="./static", template_folder='./templates')
SONGS = [KIM_POSSIBLE_SONG, RICK_ROLL]
URL = ""

def custom_message():
    song = SONGS[randint(0,1)]
    song_lines = song.split("\n")
    song_lines.insert(randint(0, len(song_lines) - 1), URL)
    return "\n".join(song_lines)


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('--port', '-p', type=str, required=True)
    args = parser.parse_args()
    return args.port


def send_packet(dst_ip, dst_port, src_port):
    pkt = scapy.Ether() / scapy.IP(dst=dst_ip) / scapy.TCP(sport=int(src_port), dport=int(dst_port))  / scapy.Raw(custom_message())
    scapy.sendp(pkt)


@app.route("/")
def index():
    dst_ip = request.environ['REMOTE_ADDR']
    dst_port = request.environ['REMOTE_PORT']
    src_port = request.environ['SERVER_PORT']
    t = Thread(target=lambda: send_packet(dst_ip, dst_port, src_port))
    t.start()
    return render_template("kimsite.html")


if __name__ == "__main__":
    port = parse_arguments()
    app.run(host='0.0.0.0', port=port)
