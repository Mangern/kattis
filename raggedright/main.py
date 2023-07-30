from sys import stdin

lines = []
mx = 0
for line in stdin:
    lines.append(len(line))
    mx = max(mx,lines[-1])

ans = 0
for i in lines[:-1]:
    ans += (mx-i)**2
print(ans)

