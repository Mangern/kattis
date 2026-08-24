from math import log2
n,x=map(int,input().split())
a=[int(input()) for _ in range(n)]
a.sort()
ans=0.0
for i,e in enumerate(a):
    num=e+x if i < n - 1 else e
    ans += log2(num/x)
print(ans)
