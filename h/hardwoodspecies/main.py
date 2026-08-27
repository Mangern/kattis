d = dict()
tot = 0
while True:
    try:
        n = input()
        if n not in d:
            d[n] = 0
        d[n] += 1
        tot += 1
    except:
        break

for w in sorted(d):
    print(f"{w} {100*d[w]/tot}")
