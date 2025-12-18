from decimal import Decimal, getcontext, ROUND_HALF_UP
k,n=map(int,input().split())
ncorr=[]
name=[]
key=input().split()

for _ in range(n):
    s=input()
    name.append(s)
    ans=input().split()
    ncorr.append(sum(1 for x,y in zip(key, ans) if x == y))

for x,y in zip(name, ncorr):
    ret=(Decimal(y * 20) / Decimal(k)).quantize(Decimal("0"), ROUND_HALF_UP)
    ret /= 2
    print(f"{x}: {ret:.1f}")
