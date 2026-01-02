def rotate(msg, amount):
    return ((msg >> amount) | (msg << (20 - amount))) & 0xfffff

def transform(msg):
    msg = msg & 0xffffffffff
    
    a = msg & 0xfffff
    a = rotate(a, 6)
    a = a ^ 0xc21f3
    a = a | 0xaaaaa

    b = (msg >> 20) & 0xfffff
    b = b ^ a
    b = b | 0xaaaaa
    b = b ^ 0xbf83f
    b = rotate(b, 6)

    a = a ^ b

    return (a << 20) | b

t=int(input())

b = t & 0xfffff
a = (t >> 20) & 0xfffff
a ^= b

for ia in range(0x100000):
    ap = rotate(ia, 6)
    ap = ap ^ 0xc21f3
    ap = ap | 0xaaaaa
    if ap == a:
        break
else:
    assert(False)


for ib in range(0x100000):
    bp = ib ^ ap
    bp = bp | 0xaaaaa
    bp = bp ^ 0xbf83f
    bp = rotate(bp, 6)
    if bp == b:
        break
else:
    assert(False)

msg = (ib << 20) | ia
print(msg)
#print(transform(msg))
