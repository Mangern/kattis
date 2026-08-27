from itertools import cycle
cip = list(map(ord, input()))
key = list(map(ord, input()))

ans = []

for c, k in zip(cip, cycle(key)):
    c -= ord('a')
    k -= ord('a')
    s = 0
    if (c + k) & 1:
        s = c + k
    else:
        s = c - k
    ans.append(chr(ord('a') + s % 26))

print("".join(ans))
