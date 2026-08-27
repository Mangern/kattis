n=int(input())
a=[tuple(map(int,input().split())) for _ in range(n)]
a=[x for x,y in a if y == 0]
if not a:
    print(-1)
else:
    print(min(a))
