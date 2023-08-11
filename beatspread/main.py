for _ in range(int(input())):
    s,d=map(int,input().split())

    if (s+d)%2 != 0 or s < d:
        print("impossible")
        continue

    a = (s+d)>>1
    b = (s-d)>>1

    print(a,b)
