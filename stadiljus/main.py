n = int(input())
x = int(input())
y = int(input())
a = list(map(int, input().split()))
a.sort()

ans = 0

sm = 0
for i in range(n):
    if x * (sm + a[i]) / (i+1) > y:
        break
    ans += 1
    sm += a[i]

print(ans)

