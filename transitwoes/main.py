s,t,n = map(int,input().split())
ds = list(map(int,input().split()))
bs = list(map(int,input().split()))
cs = list(map(int,input().split()))

for i in range(n):
    s += ds[i]
    s = ((s+cs[i]-1)//cs[i])*cs[i]
    s += bs[i]

s += ds[-1]
print("yes" if s <= t else "no")
