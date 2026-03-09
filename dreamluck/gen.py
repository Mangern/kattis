from random import randint
n=20
k=5

a = [randint(0, 10) for _ in range(n)]
print(n, k)
print(" ".join(map(str,a)))
