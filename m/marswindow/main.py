mo = 3
yr = 2018
y = int(input())

while yr < y:
    yr += 2
    mo += 2
    if mo >= 12:
        mo -= 12
        yr += 1

print("yes" if yr == y else "no")
