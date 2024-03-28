import random
import os

while True:
    n = 2 * random.randint(2, 7)
    L = random.randint(1, 10000)
    W = random.randint(1,20)

    p = [random.randint(0, L) for _ in range(n)]

    with open("in.in", "w") as f:
        f.write(f"{n} {L} {W}\n")
        f.write(" ".join(map(str, p)) + "\n")

    os.system("./main < in.in > out.out")
    my_res = float(open("out.out").read())
    os.system("./brute < in.in > out.out")
    brute_res = float(open("out.out").read())

    if abs(my_res - brute_res) > 10**-6:
        print("WRONG ANSWER")
        print(f"{n} {L} {W}")
        print(" ".join(map(str, p)))
        exit()
    else:
        print("ACCEPTED")
