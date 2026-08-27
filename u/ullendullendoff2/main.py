n=int(input())
a=[input() for _ in range(n)]
if 12%n != 0:
    a[0], a[12%n] = a[12%n], a[0]
print("\n".join(a))
