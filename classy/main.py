for _ in range(int(input())):
    n = int(input())
    ppl = []
    cid = {"lower": 3, "middle": 2, "upper": 1}
    mlen = 0
    for i in range(n):
        name, clas = input().strip().split(": ")
        clas = clas.split()[0]
        clist = [cid[k] for k in clas.split("-")][::-1]
        ppl.append([name, clist])
        mlen = max(mlen, len(clist))

    for i in range(n):
        while len(ppl[i][1]) < mlen:
            ppl[i][1].append(2)
        ppl[i][1] = tuple(ppl[i][1])

    ppl.sort(key = lambda t: (t[1], t[0]))
    #for p in ppl:
    #    print(p[0], p[1])
    print("\n".join(n for n, _ in ppl))
    print("="*30)
