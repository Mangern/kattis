for _ in range(int(input())):
    s = input()
    t = input()
    print(s)
    print(t)
    n = int(t.split()[0])
    adr = []
    while n:
        s = input()
        if s[0] == '+':
            x,y,z=map(int,s.split()[1:])
            cnt = 0
            for tgs in range(x,y+1,z):
                adr.append(tgs)
                cnt += 1
            n -= cnt
        else:
            n -= 1
            adr.append(int(s))
    adr = [str(x) for x in adr]
    mp = [0 for i in range(10)]
    for s in adr:
        for c in s:
            mp[ord(c)-ord('0')] += 1
    sm = 0
    for i,x in enumerate(mp):
        print(f"Make {x} digit {i}")
        sm += x
    print(f"In total {sm} digit{'' if sm == 1 else 's'}")

