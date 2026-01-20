from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import os

KEY = os.urandom(16)
FLAG = "HexDefender{???}"

def _p(e):
    e = e.replace("&", "").replace("=", "")
    return f"email={e}&uid=10&role=user"

def _e(e):
    c = AES.new(KEY, AES.MODE_ECB)
    return c.encrypt(pad(_p(e).encode(), 16)).hex()

def _d(t):
    try:
        c = AES.new(KEY, AES.MODE_ECB)
        return unpad(c.decrypt(bytes.fromhex(t)), 16).decode()
    except: return None

def _check(t):
    p = _d(t)
    if p:
        d = dict(i.split("=") for i in p.split("&"))
        if d.get('role') == 'admin': return FLAG
    return "No"

