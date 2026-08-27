import os
import random

while True:
    q = random.randint(1, 10)
    C, R = 10, 10
    ts = [random.randint(1, 10) for _ in range(q)]
    ts.sort()

    points = [(random.randint(0, C-1), random.randint(0, R-1)) 
              for _ in range(q)]

    with open("in.in", "w") as f:
        f.write(f"{C} {R}\n")
        f.write(f"{q}\n")

        for i in range(q):
            f.write(f"{ts[i]} {points[i][0]} {points[i][1]}\n")

    os.system("./order < in.in > out.out")

    ordered_out = open("out.out").read().splitlines()
    in_order = True
    for idx, line in enumerate(ordered_out):
        t, x, y = map(int, line.split())

        if (x,y) != points[idx]:
            in_order = False
            break

    if not in_order:
        continue

    os.system("./bad < in.in > out.out")
    bad_out = open("out.out").read().splitlines()

    for idx, line in enumerate(bad_out):
        if line != ordered_out[idx]:
            print("WRONG ANSWER")
            print("    Did not produce correct order")
            exit()

    print("ACCEPTED")
