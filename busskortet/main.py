n = int(input())

r = (n // 100) * 100

def check(x):
    if x <= 0:
        return 0
    x //= 100
    # 500 * a + 200 * b + 100 * c == x
    # 500 * a + 200 * b == x - 100 * c
    # x % 100 = 0
    # 5 * a + 2 * b = x - c
    
    sm = 10000000000000000
    for a in range(x):
        if 5*a > x:
            break
        for b in range(x):
            if 5*a+2*b > x:
                break
            c = x - 5 * a - 2 * b

            sm = min(sm,a+b+c)
    return sm

ans = -1
if r == n:
    ans = check(n)
else:
    ans = check(r)+1
    ans = min(ans,check(r-100)+1)
    ans = min(ans,check(r-400)+1)

print(ans)
