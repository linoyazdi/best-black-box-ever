from itertools import cycle


KEY = 'mesugaloot'
FLAG = 'https://mail.google.com/mail/u/0/?tab=wm#inbox/FMfcgzGrbHtTKgSWbtLPdCrSffLHJBrT'


def xor_decrypt(message, key):
    return ''.join(chr(ord(c) ^ ord(k)) for c, k in zip(message, cycle(key)))


if __name__ == '__main__':
    encrypted_flag = xor_decrypt(FLAG, KEY)
    print(encrypted_flag)
    print(xor_decrypt(encrypted_flag, KEY))
