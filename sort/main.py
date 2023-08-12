n,c=map(int,input().split())
a = list(map(int,input().split()))
cnt = dict()
time = dict()
for i,x in enumerate(a):
    if x not in time:
        time[x] = i
    if x not in cnt:
        cnt[x] = 0
    cnt[x] += 1

a.sort(key=lambda x: (-cnt[x],time[x]))
print(" ".join(map(str,a)))
