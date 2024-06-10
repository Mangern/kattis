
months = [
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
]

def getd(m, d):
    sm = 0

    for i in range(m - 1):
        sm += months[i]
    return sm + d - 1


ds = []

for _ in range(int(input())):
    s, t = input().split()

    m, d = map(int, t.split("-"))
    ds.append(getd(m, d))

ds.sort()

ds += ds

best = 0
bgap = 0
anch = getd(10, 27)+2
#print(anch)

for i, (d1, d2) in enumerate(zip(ds, ds[1:])):
    if (d2 - d1) % 365 > bgap:
        bgap = (d2 - d1) % 365
        best = i+1
    elif (d2 - d1) % 365 == bgap:
        #print((d2 - anch) % 365)
        #print((ds[best] - 1 - anch) % 365)
        if (d2 - anch) % 365 < (ds[best] - anch) % 365:
            best = i+1

ans = (ds[best] - 1)%365

sm = 0
for i in range(12):
    if sm + months[i] > ans:
        break
    sm += months[i]

am = i+1
ad = ans - sm + 1
print(f"{am:02d}-{ad:02d}")
