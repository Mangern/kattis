import random
for i in range(1000):
    n = random.randint(1,500)

    print(n)

    for j in range(n):
        x = random.randint(-5,5)
        y = random.randint(-5,5)
        print(f"{x} {y}")

print(0)
