p1,l1,c1 = 60,1000,5
p2,l2,c2 = 11,8000,60

h, P = map(int,input().split())

d = 1
htot = 0
while True:
    htot += h

    n1 = (htot + l1 - 1) // l1

    k1 = p1 * htot * P / 100000 + n1 * c1
    k2 = p2 * htot * P / 100000 + c2

    if k2 < k1:
        print(d)
        break
    d += 1
