import random
m = 40
S = 300

print(100)
for _ in range(100):
    print(m, S)

    for _ in range(m-1):
        print(random.randint(0, S), random.randint(0, S))
    print(0, 0)
