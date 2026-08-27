def tomin(s):
    hr,mn=map(int,s.split(":"))
    return int(hr)*60+int(mn)
n=int(input())
ans=10**10
for _ in range(n):
    t=input().split()
    starts=[w.split("-")[0] for w in t]
    ends=[w.split("-")[1] for w in t]
    starts = list(map(tomin,starts))
    ends = list(map(tomin,ends))
    ans=min(ans,sum(y-x for x,y in zip(ends, starts[1:])))
print(ans)
