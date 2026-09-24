h=int(input())
ans=0
for i in range(h):
    ans += 4**i
    ans -= (i+1)**2
print(ans)
