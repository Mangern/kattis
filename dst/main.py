for _ in range(int(input())):
    dir,d,h,m=input().split()
    d,h,m=map(int,(d,h,m))
    if dir == 'B':
        d = 24*60-d

    m += d
    while m >= 60:
        m -= 60
        h += 1
        h %= 24
    print(h,m)
