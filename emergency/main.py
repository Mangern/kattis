n, k = map(int, input().split())
n -= 1

if n <= k:
    print(n)
    exit(0)

nmult = (n // k) * k
ans = k + n - nmult
if nmult != k:
    ans += 1


print(ans)
