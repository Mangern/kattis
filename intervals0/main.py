n,k=map(int,input().split())
ar=[0]*24
for _ in range(n):
    a,b=map(int,input().split())
    for i in range(a,b):
        ar[i] += 1
print(sum(1 for x in ar if x >= k))
