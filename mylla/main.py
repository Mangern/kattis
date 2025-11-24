a=0
b=0
aa=0
bb=0
input()
s = input()

for c in s:
    if c == 'A':
        a += 1
    else:
        b += 1

    if a == 3:
        a = 0
        b = 0
        aa += 1
    elif b== 3:
        a = 0
        b = 0
        bb += 1

print("Hannes" if aa > bb else "Arnar")
