import random

n = 100

a = sorted(random.sample(range(1,10**6+1), n))
print(n)
print(" ".join(map(str,a)))
