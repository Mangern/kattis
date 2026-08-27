n = int(input())

ps = [float(input().split()[1]) for i in range(n)]

ps.sort(key=lambda t: -t)

ans = 0

for i,x in enumerate(ps):
    ans += (i + 1) * x

print(ans)
