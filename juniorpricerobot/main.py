n=int(input())
p=list(map(int,input().split()))

ans="infinity"
for i in range(1, n):
    if p[i] <= p[0]:
        ans=i
        break
print(ans)
