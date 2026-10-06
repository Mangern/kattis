input()
ds=list(map(int,input().split()))
print(sum(sum(range(d+1))/d for d in ds))
