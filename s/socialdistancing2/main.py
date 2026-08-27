s,n=map(int,input().split())

a = list(map(int,input().split()))

if n == 1:
    print((s-2)>>1)
    exit()

b = []
b.append(a[0]-1+s-a[-1])

for x,y in zip(a,a[1:]):
    b.append(y-x-1)

print(sum((x-1)>>1 for x in b))
