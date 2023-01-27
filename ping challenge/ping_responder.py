import scapy.all as scapy
import base64
import argparse

NEXT_LEVEL_MESSAGE = b'well done'


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('--interface', '-eth', type=str, required=True)
    parser.add_argument('--ip', '-i', type=str, required=True)
    args = parser.parse_args()
    return args.ip, args.interface


RESPONSE_TYPE = 0

def convert_to_scapy(raw_packet):
    new_pkt = scapy.Ether()
    new_pkt.dissect(raw_packet)
    return new_pkt


def pkt_callback(pkt, ip):
    new_pkt = convert_to_scapy(pkt.build())
    if new_pkt['IP'].dst == ip:
        out_pkt = scapy.Ether(dst=new_pkt['Ether'].src) / scapy.IP(dst=new_pkt['IP'].src) / scapy.ICMP(type=RESPONSE_TYPE, id=new_pkt['ICMP'].id, seq=new_pkt['ICMP'].seq) / scapy.Raw(base64.encodebytes(NEXT_LEVEL_MESSAGE)) / new_pkt
        scapy.sendp(out_pkt)


if __name__ == '__main__':
    ip, interface = parse_arguments()
    scapy.sniff(iface=interface, prn=lambda pkt: pkt_callback(pkt, ip), filter='icmp', store=0)
