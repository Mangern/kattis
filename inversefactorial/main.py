from math import log10, floor
facs = [1]
for i in range(2, 10):
    facs.append(facs[-1] * i)

n = input()

if len(n) <= 6:
    print(facs.index(int(n)) + 1)
    exit()

lfacs = [log10(f) for f in facs]

i = 10
while lfacs[-1] < 10**6:
    lfacs.append(lfacs[-1] + log10(i))
    i += 1

l = len(n) - 1

ansi = 1
ansf = float('inf')
for i, lf in enumerate(lfacs):
    if floor(lf) == l:
        ansi = i+1
        break

print(ansi)
