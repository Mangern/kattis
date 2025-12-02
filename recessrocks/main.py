n=int(input())
a=sorted(map(int,input().split()))
print(sum(1 for x, y in zip(a, a[1:]) if x == y))
