import os
from random import randint 

def run(N, a):
    with open("input", "w") as f:
        f.write(f"{N}\n")
        f.write(" ".join(map(str, a)))

    f.close()
    os.system("./a.out < input > output")

    result = open("output").read().strip()
    return result

N = 20
M = 30

while True:
    a = [randint(1, M) for _ in range(N)]
    if randint(1,2) == 1:
        result = run(N, a)
        if result != "impossible":
            print("FAILED")
            print(N)
            print(a)
            print(result)
            print("Expected: impossible")
            break
    else:
        a.sort()
        l = randint(0, N//2)
        r = randint(l+1, N-1)

        rev = a[l:r+1][::-1]

        for i in range(l, r+1):
            a[i] = rev[i-l]

        result = run(N, a)
        if result != f"{l+1} {r+1}":
            print("FAILED")
            print(N)
            print(a)
            print(result)
            print(f"Expected: {l+1} {r+1}")
            break
