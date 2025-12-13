h1,m1,s1=map(int,input().split(":"))
h2,m2,s2=map(int,input().split(":"))

ans=[0,0,0]

while (h1, m1, s1) != (h2,m2,s2):
    s1 += 1
    s1 %= 60
    if s1 == 0:
        ans[2] += 1
        m1 += 1
        m1 %= 60
        if m1 == 0:
            ans[1] += 1
            h1 += 1
            if h1 == 12:
                ans[0] += 1
print(*ans)
