n = int(input())
a = list(enumerate(map(int,input().split())))
a.sort(key=lambda t: t[1])
a.reverse()

s = sum(x[1] for x in a)

if a[0][1]*2 > s:
    print("impossible")
else:
    print(" ".join(str(x[0]+1) for x in a))
