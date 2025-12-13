a,b,c=sorted(map(int,input().split()))
if c*c == a*a + b*b:
    print(a*b//2)
else:
    print(-1)
