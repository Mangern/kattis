n = int(input())
a = list(map(int,input().split()))

a.sort()

ans = 0
for i in range((n+1)//2):
    ans += (a[i])//2

for i in range((n+1)//2,n):
    ans += a[i]

print(ans)

