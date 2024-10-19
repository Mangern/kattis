def nCk(n, k):
    if k > n - k:
        return nCk(n, n - k)
    num = 1
    for i in range(k):
        num *= (n - i)
    for i in range(k):
        num //= (i+1)
    return num

for _ in range(int(input())):
    n, v1, v2, w = map(int, input().split())
    p = 0

    rem = n - v1 - v2

    
    for a in range((v2 + rem - v1) // 2 + 1, rem + 1):
        p += nCk(rem, a)

    if p == 0:
        print("RECOUNT!")
    elif p * 100 > w * 2**rem:
        print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
    else:
        print("PATIENCE, EVERYONE!")


