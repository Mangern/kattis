for _ in range(int(input())):
    n,e=map(int,input().split())

    for p in range(2,1000):
        if n % p == 0:
            break
    else:
        assert False
    q = n // p
    phi = (p - 1) * (q - 1)
    d = pow(e,-1,phi)
    print(d)
