n = int(input())

def gen(i, x, y):
    for i in range(i):
        x, y = x-y, x+y
    return x, y

i = 0
while (1 << i) < n:
    i += 1


x, y = 0, 0
bx, by = 1, 0
for j in range(i, -1, -1):
    if  (1 << j) == n or (j > 0 and (1 << (j-1)) < n):
        dx, dy = gen(j, bx, by)
        x += dx
        y += dy
        bx, by = by, -bx
        n = (1 << j) - n

print(x, y)

