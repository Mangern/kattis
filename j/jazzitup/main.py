def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

n = int(input())

for m in range(2,n):
    if gcd(n,m)==1:
        print(m)
        exit(0)
