n, b, h, w = map(int,input().split())

INF = 10000 * 200 * 100

m_week = [INF for i in range(w)]

for i in range(h):
    p = int(input())
    a = filter(lambda tup: tup[1] >= n, enumerate(map(int, input().split())))
    if p * n > b:
        continue
    for i,x in a:
        m_week[i] = min(m_week[i], p*n)

ans = min(m_week)
if ans == INF: ans = "stay home"
print(ans)
