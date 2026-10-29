def dec(c):
    vow="AEIOU"
    con="BCDFGHJKLMNPQRSTVWXYZ"
    if c in vow:
        return vow[(vow.index(c)-2)%len(vow)]
    if c in con:
        return con[(con.index(c)-5)%len(con)]
    return c
print("".join(map(dec,input())))
