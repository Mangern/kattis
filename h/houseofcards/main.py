n=int(input())

while True:
    c = n *(n + 1) + n * (n - 1) // 2

    if c % 4 == 0:
        print(n)
        break
    n += 1
