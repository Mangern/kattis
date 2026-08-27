n,a,b=map(int,input().split())
acov=False
bcov=False

for _ in range(n - 1):
    x=int(input())
    if x == a:
        acov=True
    if x == b:
        bcov=True

if not acov and not bcov and a != b:
    print(-1)
elif not acov:
    print(a)
elif not bcov:
    print(b)
else:
    print("\n".join(map(str,range(a,b+1))))

