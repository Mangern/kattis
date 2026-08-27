import subprocess
import random

n = 10

def gen(n):
    A = "AGCT"

    s = [random.choice(A) for _ in range(n)]

    idx = random.choice(range(n))
    len = random.randint(0, n - idx)

    t = [c for c in s]

    newlen = random.randint(0, n)

    newstr = "".join(random.choice(A) for _ in range(newlen))

    for i in range(len):
        t.pop(idx)

    t.insert(idx, newstr)

    return ("".join(s), "".join(t), newlen)

#print("Answer: ", newlen)
while True:
    process = subprocess.Popen(
        "./a.out", 
        stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE,
        text=True,
        shell=True)

    s,t,ans = gen(n)

    process.stdin.write(f"{s}\n{t}\n") # pyright: ignore
    process.stdin.flush()
    ret = process.stdout.readline() # pyright: ignore
    if int(ret) != ans:
        print("WRONG ANSWER")
        print(s)
        print(t)
        print(f"Correct: {ans}, user: {ret}")
