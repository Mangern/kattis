n,k=map(int,input().split())
d,s=map(int,input().split())

ans = (d * n - s * k) / (n - k)

if ans < 0 or ans > 100:
    print("impossible")
else:
    print(ans)
