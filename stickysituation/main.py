input()
a = list(map(int,input().split()))

a.sort()
for x,y,z in zip(a,a[1:],a[2:]):
    if x+y>z:
        print("possible")
        break
else:
    print("impossible")
