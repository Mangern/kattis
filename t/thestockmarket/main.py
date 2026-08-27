n,k=int(input()),int(input())
a=[int(input())for _ in range(n)]
print(max(x-y for x, y in zip(a[k:],a)))
