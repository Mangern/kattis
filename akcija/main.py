n =int(input())
a = [int(input()) for _ in range(n)]
a.sort()
a.reverse()
print(sum(a) - sum(a[2::3]))
