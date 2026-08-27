n=int(input())

x = 1
ans = 0
while x <= n:
    cnt = 0
    if (n & x) > 0:
        lst = n - (n & (x - 1))
        base = (lst - 1) // ( 2* x) * x
        cnt = base + (n - lst + 1)
    else:
        cnt = n // (2 * x) * x
    if cnt & 1:
        ans += x
    x *= 2
if ans == 0:
    print("Enginn")
elif ans>n:
    print("Gunnar")
else:
    print(ans)
