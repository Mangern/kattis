names = []
cnt = dict()
while True:
    try:
        s = input()
        a,b=s.split()
        names.append((a,b))
        if a not in cnt:
            cnt[a] = 0
        cnt[a] += 1
    except:
        break

names.sort(key=lambda x: (x[1],x[0]))

for a,b in names:
    if cnt[a] > 1:
        print(f"{a} {b}")
    else:
        print(a)
