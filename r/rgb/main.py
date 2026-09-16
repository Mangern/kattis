r,g,b,k=map(int,input().split())

if g == 0 and b == 0:
    print(max(r, r + k - 2))
else:
    print(r + k)
