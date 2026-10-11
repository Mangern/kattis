from random import randint

n = 3 * 10**5
w = n
bs = [randint(200, n - 1) for _ in range(n)]
print(n, w)
print(" ".join(map(str, bs)))
