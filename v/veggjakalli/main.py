n, m = map(int, input().split())
s = input()

sm = 0
for i in range(min(n-1, m)):
    if s[1+i] == '#':
        sm += 1

INF = 10**17
ans = INF
# i < n - m - 2
# i + m < n
for i in range(1, n - m):
    if s[i-1] == '#' and s[i+m] == '#':
        ans = min(ans, sm)
    if s[i] == '#':
        sm -= 1
    if s[i+m] == '#':
        sm += 1

if ans == INF:
    print("Neibb")
else:
    print(ans)
