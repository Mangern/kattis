while True:
    l = input()
    if l == "0":
        break
    k,m=map(int,l.split())
    tak = set(map(int,input().split()))
    cs = [list(map(int,input().split())) for i in range(m)]
    cs = [[c[0],c[1],c[2:]] for c in cs]

    for c,r,cr in cs:
        for x in cr:
            if x in tak:
                r -= 1
        if r > 0:
            print("no")
            break
    else:
        print("yes")
