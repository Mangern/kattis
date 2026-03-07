import re
def fail():
    print(False)
    exit()

def parse(s: str):
    if s[-1] != '"':
        fail()
    if s.find("*") == -1:
        fail()
    a, b = s.split("*")
    if a[0] != '+' and a[0] != '-':
        fail()
    c, d = b[:-1].split("'")
    if len(a) not in range(2, 5):
        fail()
    if len(c) != 2 or len(d) != 2:
        fail()
    c = int(c)
    d = int(d)
    if c not in range(60) or d not in range(60):
        fail()
    return int(a), c, d 
try:
    pat = re.compile("[+-]\d\d?\d?\*\d\d'\d\d\" [+-]\d\d?\d?\*\d\d'\d\d\"")
    s = input()

    if not pat.fullmatch(s):
        fail()
    l= s.split()
    if len(l) != 2:
        print(False)
        exit()

    a, b = l
    xa, ya, za = parse(a)
    xb, yb, zb = parse(b)
    sign = 1 if xa >= 0 else -1
    ta = xa * 3600 + sign * (60 * ya + za)
    tb = xb * 3600 + sign * (60 * yb + zb)

    if ta < -90 * 3600 or ta > 90 * 3600:
        fail()
    if tb < 0 or tb > 360 * 3600:
        fail()
    print(True)
except SystemExit:
    pass
except:
    fail()
