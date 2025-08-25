k, a, b = int(input()), int(input()), int(input())

ret = []

i = 0

while i * a <= k:
    rm = k - i * a

    if rm % b == 0:
        ret.append((i, rm // b))

    i += 1

print(len(ret))

for x, y in ret:
    print(x, y)
