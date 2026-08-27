n=int(input())
a=[int(input()) for _ in range(n)]
a.sort()
w=0

for x in a:
    nw = 2 * (x - w)
    print(nw)
    w += nw
