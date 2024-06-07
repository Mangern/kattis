poss = [True for i in range(10)]
dh = False
while True:
    g = int(input())
    if g == 0:
        break
    resp = input()
    if resp == "right on":
        # calculate ans

        if dh or not poss[g-1]:
            print("Stan is dishonest")
        else:
            print("Stan may be honest")

        poss = [True for i in range(10)]
        dh = False
        continue

    if resp == "too high":
        if not poss[g-1] and any(poss[g-1:]):
            dh = True
        for i in range(g-1, 10):
            poss[i] = False
    else:
        if not poss[g-1] and any(poss[:g]):
            dh = True

        for i in range(g):
            poss[i] = False
