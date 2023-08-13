def factors(x):
    for i in range(1,x+1):
        if i * i > x:
            break
        if x % i == 0:
            yield i
            if i * i != x:
                yield x // i

for _ in range(int(input())):
    a,b,c = map(int,input().split())

    found = False
    for e in factors(c):
        for d in factors(a):
            g = c // e
            f = a // d
            if d * g + e * f == b:
                found = True
                break
        if found:
            break

    print("YES" if found == True else "NO")


