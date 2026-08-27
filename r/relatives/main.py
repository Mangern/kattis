while True:
    n = int(input())
    if not n:
        break

    divs = []

    i = 2
    while i * i <= n:
        if n % i == 0:
            div = i

            if div > 1:
                prime = True
                for d in divs:
                    if div % d == 0:
                        prime = False
                        break

                if prime:
                    divs.append(div)

        i += 1

    i = 1
    while i * i <= n:
        if n % i == 0:
            div = n // i

            if div > 1:
                prime = True
                for d in divs:
                    if div % d == 0:
                        prime = False
                        break

                if prime:
                    divs.append(div)

        i += 1

    ans = n

    for p in divs:
        ans *= (p - 1)
        ans //= p

    print(ans)
