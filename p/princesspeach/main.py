
n,m=map(int,input().split())

a = set(int(input()) for _ in range(m))
a = list(a)
a.sort()
a.append(n)

lo = 0
for x in a:
    for i in range(lo,x):
        print(i)
    lo = x+1
a.pop()
print("Mario got {len(a)} of the dangerous obstacles.")
