from sys import stdin
fac = [1]

for i in range(1, 201):
    fac.append(fac[-1] * i)

def multi(ms):
    d = {}
    for c in ms:
        d[c] = d.get(c, 0)+1

    ret = fac[len(ms)]

    for k,v in d.items():
        ret //= fac[v]
    return ret



for line in stdin:
    print(multi(line.strip()))
