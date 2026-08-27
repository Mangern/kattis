n = int(input())
a = [int(input()) for i in range(n)]
if n & 1:
    print("still running")
    exit(0)

print(sum(y-x for x,y in zip(a[::2], a[1::2])))
