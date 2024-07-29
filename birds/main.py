l, d, n = map(int, input().split())
pos = [int(input()) for _ in range(n)]

pos.sort()

ans = 0
for i in range(1, len(pos)):
    a = pos[i] - pos[i - 1]
    ans += max(0, a - d) // d

if n == 0 and  l>=12:
    ans = (l - 12) // d + 1
else:
    ans += max(0, pos[0]-6) // d
    ans += max(0, l - 6 - pos[-1]) // d

print(ans)
