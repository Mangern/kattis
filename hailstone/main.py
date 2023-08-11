def h(x):
    if x == 1:
        return 1
    if x & 1:
        return 3 * x + 1
    return x >> 1

n = int(input())
ans = 1
while n > 1:
    ans += n
    n = h(n)

print(ans)

