n = int(input())
a = list(map(int, input().split()))
a.append(0)

ans = 0
for i in range(n):
    ans += max(0, a[i] - (1 + a[i+1]))

print(ans)

