def intersects(l1, l2):
    a,b,c,d=l1
    p,q,r,s=l2

    det = (c-a)*(s-q)-(r-p)*(d-b)
    if det == 0:
        return False

    lamb = ((s-q)*(r-a)+(p-r)*(s-b))/det
    gamm = ((b-d)*(r-a)+(c-a)*(s-b))/det
    return (0 < lamb < 1) and (0 < gamm < 1)


while True:
    n = int(input())
    if not n:
        break
    lines = [list(map(float,input().split())) for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(i+1,n):
            for k in range(j+1,n):
                if intersects(lines[i], lines[j]) and intersects(lines[i], lines[k]) and intersects(lines[j], lines[k]):
                    ans += 1
    print(ans)
