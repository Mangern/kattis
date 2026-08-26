n=int(input())
stats={}
for _ in range(n):
    name,x=input().split()
    x=int(x)
    if name not in stats:
        stats[name] = {}
    if x not in stats[name]:
        stats[name][x] = 0
    stats[name][x] += 1

ans=[]
for name in stats:
    mx=0
    mx_hold=0
    for hold in sorted(stats[name]):
        if stats[name][hold] > mx:
            mx=stats[name][hold]
            mx_hold=hold
    ans.append((name,mx_hold))
ans.sort()
for name,hold in ans:
    print(name,hold)
