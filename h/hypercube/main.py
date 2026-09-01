def pos(n, a):
    if n == 0:
        return 0
    if a[0] == "0":
        return pos(n - 1, a[1:])

    return 2**n - 1 - pos(n - 1, a[1:])

def dist(n, a, b):
    if n == 0:
        return 0

    if a[0] == b[0]:
        return dist(n - 1, a[1:], b[1:])

    return 2**n - 1 - pos(n-1, a[1:]) - pos(n-1, b[1:])
n,a,b=input().split()
n=int(n)

print(dist(n,a,b)-1)
