s=input()
n = int(input())
ans=n
for i in range(n):
    x=input()
    if len(x) != len(s):
        continue
    sc=sum(1 for a,b in zip(s,x) if a != b)
    if sc <= 1:
        ans=min(ans,i+1)
print(ans)
