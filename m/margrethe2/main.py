n=int(input())
mp={}
ppl=[]
for _ in range(n):
    s=input()
    spidx=s.find(' ')
    if spidx==-1:
        ppl.append((s,""))
    else:
        ppl.append((s[:spidx], s[spidx:]))
    fst=ppl[-1][0]
    mp[fst] = mp.get(fst, 0) + 1


use={k: 1 for k in mp}
for fst, rem in ppl:
    if mp[fst] == 1:
        print(fst+rem)
    else:
        print(fst + " " + f"{use[fst]}."+rem)
        use[fst] += 1
