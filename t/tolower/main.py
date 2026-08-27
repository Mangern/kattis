p,t=map(int,input().split())

ans = 0
for i in range(p):
    al = True 
    for j in range(t):
        s = input()
        s = s[0].lower() + s[1:]

        if s.lower() != s:
            al = False
    if al:
        ans += 1
print(ans)
