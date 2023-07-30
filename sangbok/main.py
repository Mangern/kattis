
t,n=map(int,input().split())
s = list(map(int,input().split()))
s.sort()
s.reverse()
ans=0
t*=60
while t and s:
    x = s.pop()
    if x > t:
        break
    ans += x
    t -= x
print(ans)

