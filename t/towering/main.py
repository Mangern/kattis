from itertools import combinations

a = list(map(int,input().split()))
h2,h1=a.pop(),a.pop()

a.sort()
a.reverse()

for x,y,z in combinations(a, 3):
    if x+y+z == h1:
        print(x,y,z,end=" ")
        a = [str(l) for l in a if l not in (x,y,z)]
        print(" ".join(a))
        break


