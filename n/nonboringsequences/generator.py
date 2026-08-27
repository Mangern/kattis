import random

T = 7

with open("in.in", "w") as f:
    f.write(f"{T}\n")
    for _ in range(T):
        n = random.randint(200000, 200000)
        a = [random.randint(1, 10**5) for _ in range(n)]
        f.write(f"{n}\n")
        f.write(" ".join(map(str, a)) + "\n")
