n,p=map(int,input().split())

a =list(map(int,input().split()))
a.sort()

d = a[0]

for i,x in enumerate(a):
    d = max(d, p * (i+1)-(x-a[0]))

print(d)

