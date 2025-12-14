for _ in range(int(input())):
    b=int(input())
    m=int(input())
    k=int(input())
    for i in range(m):
        a = list(map(int,input().split()))[:-1]
        v = 0
        for x in a:
            v = v * b + x
        if v % k == 0 and max(a) < b:
            print(1,end="")
        else:
            print(0,end="")
    print()
