n,k=map(int,input().split())
a=list(map(int,input().split()))

cnt = [0 for i in range(k+1)]
for i in a:
    cnt[i] += 1

mn = cnt[1]
minis = []
for i in range(1,k+1):
    if cnt[i] < mn:
        mn = cnt[i]
        minis = [i]
    elif cnt[i] == mn:
        minis.append(i)
minis.sort()
print(len(minis))
print(" ".join(map(str,minis)))
