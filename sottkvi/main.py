n, k, d = map(int,input().split())
k += d

ans = 0
for _ in range(n):
    a = int(input())
    if a + 14 <= k:
        ans += 1
print(ans)
