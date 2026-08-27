n = int(input())
a = [int(input()) for _ in range(n)]

ls = 0
rs = sum(a)
ans = 0 
for x in a:
    rs -= x
    ls += x * x
    ans = max(ans, ls * rs)

print(ans)

