def mp(s):
    return (ord(s[0])-ord('A'),ord(s[1])-ord('A'))
n = int(input())
x,y=mp(input())
ans = 0
for _ in range(n-1):
    x1,y1 = mp(input())
    ans += abs(x1-x)+abs(y1-y)
    x,y=x1,y1
print(ans)
