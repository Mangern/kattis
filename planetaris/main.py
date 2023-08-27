n, a = map(int, input().split())
xs = list(map(int, input().split()))
xs.sort()
ans = 0

for x in xs:
    if x < a:
        a -= x+1
        ans += 1
    else:
        break
print(ans)
