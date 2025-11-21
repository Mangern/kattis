n = int(input())
ans = 0

for i in range(n+1):
    ans += i * (i + 1) // 2

print(n * (n  +1) // 2)
print(ans)
