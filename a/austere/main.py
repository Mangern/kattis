n, k = map(int, input().split())
ans=[]
ws = input().split()
freq={}
for w in ws:
    for c in w:
        freq[c] = freq.get(c, 0) + 1
lst=sorted(freq.items(), key=lambda t: -t[1])
topk="".join(x[0] for x in lst[:k])
for w in ws:
    res=[]
    for c in w:
        if c in topk:
            res.append(c)
        else:
            res.append(topk[0])
    ans.append("".join(res))
print(" ".join(ans))
