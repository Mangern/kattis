p,q=map(int,input().split())
s=input()
poss=[[] for _ in range(4)]
for i in range(4):
    if s[i] == 'A':
        poss[i] = [[p, q][1 if i != s.index('A') else 0]]

pidx = [i for i in range(4) if p in poss[i]][0]
qidx = [i for i in range(4) if q in poss[i]][0]

for num in range(1,10):
    if num in [p,q]:
        continue
    if num < p:
        for i in range(pidx):
            if i + 1 <= num and pidx - i <= p - num:
                poss[i].append(num)
    elif num < q:
        for i in range(pidx+1, qidx):
            if qidx - i <= q - num and i - pidx <= num - p:
                poss[i].append(num)
    else:
        for i in range(qidx+1, 4):
            if 4 - i <= 10 - num and i - qidx <= num - q:
                poss[i].append(num)

ans=[]
for i in range(4):
    if s[i] == 'B':
        if len(poss[i]) == 1:
            ans.append(poss[i][0])
if len(ans)==2:
    print(ans[0], ans[1])
else:
    print(-1)
