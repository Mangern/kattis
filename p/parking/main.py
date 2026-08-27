a,b,c=map(int,input().split())

cnt = dict()

for i in range(3):
    l,r=map(int,input().split())
    for j in range(l,r):
        if j not in cnt:
            cnt[j] = 0
        cnt[j] += 1

print(sum(c*x if x >= 3 else (b*x if x >= 2 else a*x) for x in cnt.values()))
