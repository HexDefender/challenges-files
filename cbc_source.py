import os
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from binascii import hexlify, unhexlify

KEY = os.urandom(16)
FLAG = "HexDefender{???}"

def _x(u):
    d = f'username={u};role=user'.encode()
    c = AES.new(KEY, AES.MODE_CBC)
    return hexlify(c.iv + c.encrypt(pad(d, 16))).decode()

def _y(t):
    try:
        r = unhexlify(t)
        iv = r[:16]
        ct = r[16:]
        c = AES.new(KEY, AES.MODE_CBC, iv)
        p = unpad(c.decrypt(ct), 16).decode('latin-1')
        if ";role=root" in p: return True, p
        return False, p
    except: return False, "Err"
