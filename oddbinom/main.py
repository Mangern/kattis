def solve(n):
    if n == 0:
        return 0
    k = 0
    sm = 1

    while ((1<<(k+1))<= n):
        k += 1
        sm *= 3

    return sm + 2 * solve(n - (1<<k))


print(solve(int(input())))
