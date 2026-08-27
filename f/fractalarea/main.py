from math import pi
def solve(n, r):
    if n == 0:
        return 0

    return pi * r * r + 3 * solve(n - 1, r / 2)

for _ in range(int(input())):
    r,n=map(int,input().split())
    print(pi*r*r + 4*solve(n-1, r/2))
