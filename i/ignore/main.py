from sys import stdin
def base7(n):
    pw = 1
    cnt = 1
    while pw*7 <= n:
        pw *= 7
        cnt += 1
    for _ in range(cnt):
        k = n // pw
        yield k
        n -= k * pw
        pw //= 7
for line in stdin:
    k = int(line)
    res = base7(k)
    print("".join("0125986"[d] for d in res)[::-1])
