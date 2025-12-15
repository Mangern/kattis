n,m,s=map(int,input().split())
ans=0
for _ in range(n):
    ans += sum(1 for c in input() if c == '.')
print(f"Your destination will arrive in {ans*s+s} meters")
