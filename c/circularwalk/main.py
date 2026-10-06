from math import gcd
n,b,k=map(int,input().split())
print("YES" if b % gcd(n,k)==0 else "NO")
