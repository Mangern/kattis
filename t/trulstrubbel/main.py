s = input()
t = 0
h = 0
for c in s:
    if c == 'H':
        h += 1
        if h >= 11 and h >= t + 2:
            h = 0
            t = 0
    else:
        t += 1
        if t >= 11 and t >= h + 2:
            h = 0
            t = 0
print(f"{t}-{h}")
