from math import gcd
for _ in range(int(input())):
    s11,s12,p11,p12 = map(int,input().split())
    s21,s22,p21,p22 = map(int,input().split())

    p = gcd(p11,gcd(p12,gcd(p21,p22)))

    a = [[s11%p,s12%p],[s21%p,s22%p]]
    if a[0][0] > a[1][0]:
        a[0], a[1] = a[1], a[0]

    dif = a[1][0] - a[0][0]

    a[0][0] += dif
    a[0][1] += dif
    a[0][1] %= p

    if a[0][1] == a[1][1]:
        print("Yes")
    else:
        print("No")

