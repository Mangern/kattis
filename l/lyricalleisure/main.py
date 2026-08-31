n,k=map(int,input().split())
res=["a"]*k
for i in range(n-k):
    res.append("bcd"[i%3])
print("".join(res))
