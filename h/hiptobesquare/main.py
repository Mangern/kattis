for _ in range(int(input())):
    n=int(input())
    if n < 8:
        print(0)
        continue

    k = 3
    while (k+2)*(k+2) - 1 <= n:
        k += 2

    lays = k//2
    print(lays)
