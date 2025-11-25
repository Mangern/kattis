n=int(input())
plc=[[] for _ in range(5)]
for _ in range(n):
    a,b=map(int,input().split())
    plc[a-1].append(b)
av=[(sum(l)//len(l),i) for i,l in enumerate(plc)]
a,b=min(av)
print(b+1)
print(a)
