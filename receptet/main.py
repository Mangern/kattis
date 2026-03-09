ans=0
for _ in range(int(input())):
    h,b,k=map(int,input().split())
    ans += max(0, b - h)*k
print(ans)
