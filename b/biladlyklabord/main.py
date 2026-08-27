prv = ''

for c in input():
    if c == prv:
        continue
    print(c,end="")
    prv=c
print()
