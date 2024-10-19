from math import lcm
while True:
    n = int(input())
    if n == 0:
        break

    lb = 0
    ub = float('inf')

    d = 1
    for _ in range(n):
        s = input()
        if s.startswith("less than"):
            ub = min(ub, int(s.split()[-1]))
        elif s.startswith("greater than"):
            lb = max(lb, int(s.split()[-1]))
        else:
            d = lcm(d, int(s.split()[-1]))

    if ub == float('inf'):
        print("infinite")
    else:
        lst = []
        for i in range(lb+1, ub):
            if i % d == 0:
                lst.append(i)

        print("none" if not lst else " ".join(map(str, lst)))

