from math import log2
def bts(y):
    dw = (y - 1960)//10
    return (4<<dw)

l = [0.0]
for i in range(2, 260000):
    l.append(l[-1] + log2(i))

while True:
    y = int(input())
    if y == 0:
        break
    b = bts(y)
    for i in range(len(l)):
        if l[i] >= b:
            print(i)
            break
