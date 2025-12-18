n=int(input())
a=[int(input()) for _ in range(n)]
a=[x for x in a if x != 0]
if not a:
    print(0)
    exit()
print(sum(a) - (len(a) - 1))
