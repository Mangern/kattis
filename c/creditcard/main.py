for _ in range(int(input())):
    r, b, m = map(lambda x: int("".join(c for c in x if c != ".")), input().split())


    count = 0
    while count <= 1200 and b > 0:
        pay = b * r
        pays = str(pay)
        pay //= 10000
        # 101231.5123
        if len(pays) >= 4 and ord(pays[-4]) >= ord('5'):
            pay += 1

        b += pay
        #print(b)
        b = max(0, b - m)
        count += 1

    print(count if count <= 1200 else "impossible")
