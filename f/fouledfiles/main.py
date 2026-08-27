for _ in range(int(input())):
    s = input()
    res=[]

    skip = False
    for c in s:
        if len(res) >= 40:
            continue
        if skip:
            skip = False
            continue
        res.append(c)
        skip = True
    print("".join(res))
