from math import pow, floor
while True:
    x = int(input())
    if not x:
        break
    s = input()
    p = input()
    c = input()
    n = len(c)

    d = floor(pow(n,1.5)+x)%n

    def gets(ch):
        idx = s.index(ch)
        return p[idx]
    m = ["." for i in range(n)]
    m[d] = gets(c[d])
    #c[d-1] = s[p.index(m[j])^s.index(m[(j+1)%n])]
    #pos = p.index(m[i]) ^ s.index(m[i+1])
    for i in range(d-1,-1,-1):
        pos = s.index(c[i])
        posm = s.index(m[i+1])
        pidx = pos ^ posm
        m[i] = p[pidx]
    for i in range(n-1,d,-1):
        pos = s.index(c[i])
        posm = s.index(m[(i+1)%n])
        pidx = pos ^ posm
        m[i] = p[pidx]

    print("".join(m))
