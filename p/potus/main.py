def sqrt(n):
    s=int(n**0.5)

    if s * s == n:
        return s

    if (s-1)*(s-1)==n:
        return s-1

    if (s+1)*(s+1) == n:
        return s+1

    return -1

n=int(input())

s=sqrt(n)

if s == -1 or s == 1:
    print(0)
    exit()


ans = 0
for k in range(2, s+1):
    if k * k >= s:
        break

    if s % k == 0:
        ans += 1
print(ans)
