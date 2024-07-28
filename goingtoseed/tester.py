import random
import subprocess

n = 1_000_000_000

def move(mole):
    global n
    if mole == 1:
        return mole + 1
    if mole == n:
        return mole - 1
    if random.randint(1, 2) == 1:
        return mole + 1
    return mole - 1

def check(mole: int, query: str):
    _, l1, r1, l2, r2 = query.split()
    l1, r1, l2, r2 = map(int, (l1,r1,l2,r2))
    w1 = int(l1 <= mole <= r1)
    w2 = int(l2 <= mole <= r2)
    return f"{w1} {w2}"

process = subprocess.Popen(
    "./a.out", 
    stdin=subprocess.PIPE, 
    stdout=subprocess.PIPE,
    text=True,
    shell=True)

process.stdin.write(f"{n}\n") # pyright: ignore
process.stdin.flush()
mole = random.randint(1, n)
used = 0

while True:
    user = process.stdout.readline() # pyright: ignore
    print(f"User said: {user}")
    if user[0] == 'A':
        uans = int(user.split()[-1])
        print(f"Mole was at: {mole}")
        print("Correct!" if mole == uans else "wrong answer")
        print(f"Used {used} queries.")
        break
    else:
        mole = move(mole)
        used += 1
        if used > 100:
            print("User used too many queries!")
            break
        ret = check(mole, user)
        print(f"    {ret}")
        process.stdin.write(f"{ret}\n") # pyright: ignore
        process.stdin.flush()
