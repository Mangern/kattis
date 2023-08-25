def shuffle(a, outshuf):
    if outshuf:
        mid = (len(a)+1)//2
        fhalf = list(a[:mid])
        shalf = list(a[mid:])
        i = 0
        for x, y in zip(fhalf, shalf):
            a[i] = x
            a[i+1] = y
            i += 2
        if len(a) & 1:
            a[i] = fhalf[-1]
    else:
        mid = len(a)//2
        fhalf = list(a[:mid])
        shalf = list(a[mid:])
        i = 0
        for x, y in zip(shalf, fhalf):
            a[i] = x
            a[i+1] = y
            i += 2
        if len(a) & 1:
            a[i] = shalf[-1]

n, t = input().split()
n = int(n)

a = list(range(n))

shuffle(a, t == "out")

ans = 1

while a != sorted(a):
    shuffle(a, t == "out")
    ans += 1

print(ans)
