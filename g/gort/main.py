n=int(input())
a=[int(input()) for _ in range(n)]
a.sort()
a.reverse()
k=int(input())
l=1
while k * (l + 1) <= n:
    l += 1
print(sum(a[:k*l]))
