def smallf(n):
    for i in range(2,n):
        if n % i == 0:
            return i
        if i * i > n:
            break
    return n

x = int(input())

ans = 0

while x > 1:
    ans += 1
    x //= smallf(x)

print(ans)
