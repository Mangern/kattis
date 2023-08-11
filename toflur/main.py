n = int(input())
a = list(map(int,input().split()))
a.sort()
print(sum((x-y)*(x-y) for x,y in zip(a,a[1:])))

