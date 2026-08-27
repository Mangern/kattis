for _ in range(int(input())):
    input()
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a.sort()
    b.sort()
    print(f"Case #{_+1}: {sum(x*y for x,y in zip(a,b[::-1]))}")
