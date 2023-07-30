n,p,k=map(int,input().split())
ts = [0] + list(map(int,input().split())) + [k]

ans = 0.0
for i,(ts,te) in enumerate(zip(ts,ts[1:])):
    t = te-ts
    ans += (100+i*p)*t/100

print(ans)
