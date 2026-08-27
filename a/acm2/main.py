n,p=map(int,input().split())
a=list(map(int,input().split()))

num=0
pen=0
t=0
a = [a[p]] + sorted([x for i,x in enumerate(a) if i != p])
while len(a) and t+a[0] <= 300:
    t += a[0]
    num += 1
    pen += t
    a=a[1:]
print(num,pen)
