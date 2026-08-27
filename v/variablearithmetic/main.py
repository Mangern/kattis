vars = dict()
while True:
    s = input()

    if s == "0":
        break

    if "=" in s:
        w,x=s.split(" = ")
        vars[w] = int(x)
    else:
        s = s.split(" + ")
        num = 0

        rm = []
        hadnum = False
        for w in s:
            if w.isnumeric():
                num += int(w)
                hadnum = True
            elif w in vars:
                num += vars[w]
                hadnum = True
            else:
                rm.append(w)
        if hadnum:
            rm.insert(0, str(num))
        print(" + ".join(rm))
