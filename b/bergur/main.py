n=int(input())
a=list(map(int,input().split()))
for i in range(n-2,-1,-1):
    a[i] = min(a[i],a[i+1])
print(sum(a))
