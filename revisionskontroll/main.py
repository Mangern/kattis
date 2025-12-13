n=int(input())
vis=set()
for x in map(int,input().split()):
    if x in vis:
        print(0, end=" ")
    else:
        print(1, end=" ")
        vis.add(x)
print()
