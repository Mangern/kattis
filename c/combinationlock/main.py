def dist(a,b,dir):
    if dir=="cw":
        # a - x % 40 == b
        # x = a - b % 40
        return ((a - b) % 40) * 9
    else:
        # a + x == b
        return ((b - a) % 40) * 9

while True:
    s,a,b,c=map(int,input().split())
    if s==a==b==c==0:
        break
    ans=2*360
    ans+=dist(s,a,"cw")
    s=a
    ans+=360
    ans+=dist(s,b,"ccw")
    s=b
    ans+=dist(s,c,"cw")
    print(ans)

