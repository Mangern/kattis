ans = 0
for _ in range(int(input())):
    u, d = map(int, input().split())

    if u % 8 != 0 and d not in range(1, 10**4+1):
        ans += 1
print(ans)
