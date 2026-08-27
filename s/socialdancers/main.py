l,f,m=map(int,input().split())
cl=[0,0,0]
cf=[0,0,0]
idx={"swing":0, "country":1,"bachata":2}
for _ in range(l):
    know=input().split()[1:]
    for k in know:
        cl[idx[k]] += 1
for _ in range(f):
    know=input().split()[1:]
    for k in know:
        cf[idx[k]] += 1
cnt=[min(a,b) for a,b in zip(cl,cf)]
ans=1/3*sum(cnt)
print(ans*m)
