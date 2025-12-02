k=int(input())
a=[int(input()) for _ in range(k)]
n=int(input())
a += [0,0,0]*n
d={}
for x in a:
    if x not in d:
        d[x] = 0
    d[x] += 1
while True:
    mx=-1
    for k in d:
        if d[k]>1:
            mx=max(mx,k)
    if mx==-1:
        break
    d[mx] -= 2
    if mx+1 not in d:
        d[mx+1] = 0
    d[mx+1]+=1
    if d[mx] == 0:
        del d[mx]
print(" ".join(map(str,sorted(d.keys()))))
