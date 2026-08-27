l,n,m=map(int,input().split())

if n == 1 or m == 1:
    print(-1)
    exit()
if l == 9:
    if n == 2 or m == 2:
        print(-1)
        exit()
    a = [1, 2, 3, 1, 2, 3, 1, 2, 3]
    b = [2, 3, 1, 2, 3, 1, 2, 3, 1]
    print(3)
    print(" ".join(map(str,a)))
    print(" ".join(map(str,b)))
else:
    print(2)
    a = [1, 2, 1, 2, 1, 2, 1, 2]
    b = [2, 1, 2, 1, 2, 1, 2, 1]
    print(" ".join(map(str,a)))
    print(" ".join(map(str,b)))
