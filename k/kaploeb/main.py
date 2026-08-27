l,k,s=map(int, input().split())

time={}
count={}

for _ in range(l):
    id,t=input().split()
    id=int(id)
    m,s=map(int,t.split("."))

    t = m * 60 + s

    if id not in time:
        time[id] = 0
        count[id] = 0
    count[id] += 1
    time[id] += t

ans=[]
for i in time:
    if count[i] == k:
        ans.append((time[i], i))

ans.sort()
for a,b in ans:
    print(b)
