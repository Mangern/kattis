c,x,m=map(float,input().split())
eff = [list(map(float,input().split())) for _ in range(6)][::-1]

c /= 2

for mph, mpg in eff:
    hrs = m / mph
    gallos = x * hrs + m / mpg 
    if gallos <= c:
        print("YES", int(mph))
        exit(0)
print("NO")
