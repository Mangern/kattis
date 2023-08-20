y = int(input())

mayjune = [i % 7 for i in range(63)]

def leap(year):
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return year % 4 == 0

def cycle(a):
    a.append(a.pop(0))

for x in range(2000,y):
    cycle(mayjune)
    if leap(x+1):
        cycle(mayjune)

found  = 0
mayday = 0
for i in range(30):
    if mayjune[i] == 6:
        found += 1
        if found == 2:
            mayday = i
            break

juneday = 0
found = 0
for i in range(31,31+30):
    if mayjune[i] == 6:
        found += 1
        if found == 3:
            juneday = i
            break

print(f"{(juneday - mayday)//7} weeks")
