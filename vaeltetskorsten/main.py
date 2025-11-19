ans=0
for _ in range(int(input())):
    a, b = input().split()
    if b == "nej":
        ans = max(ans,int(a))
print(ans)    
