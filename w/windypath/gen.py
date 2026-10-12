from random import randint
n = int(input())

pts = []

for _ in range(n):
    while True:
        x = randint(0, 1000)
        y = randint(0, 1000)

        ok = True
        for i in range(len(pts)):
            for j in range(i + 1, len(pts)):
                x1, y1 = pts[i]
                x2, y2 = pts[j]

                ux = x2 - x1
                uy = y2 - y1
                vx = x - x1
                vy = y - y1

                if ux * vy - vx * uy == 0:
                    ok = False
                    break
            if not ok:
                break
        if ok:
            pts.append((x, y))
            break

print(n)
for x, y in pts:
    print(x, y)

s = []
for _ in range(n - 2):
    if randint(1, 2) == 2:
        s.append("R")
    else:
        s.append("L")
print("".join(s))
