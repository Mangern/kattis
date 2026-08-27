g,r=map(int,input().split())
m = min(g,r)
ans=0
ans += 10 * m
g -= m
r -= m
while g>=3:
    ans += 10
    g -= 3
while g>=2:
    ans += 3
    g -= 2
ans += g
print(ans)
