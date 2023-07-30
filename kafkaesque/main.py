n = int(input())
a = [int(input()) for i in range(n)]

ans = 1

for x,y in zip(a,a[1:]):
    if y < x:
        ans += 1
print(ans)
