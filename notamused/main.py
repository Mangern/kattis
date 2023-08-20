daycnt = 0
while True:
    try:
        input()
        daycnt += 1

        pay = dict()
        ptime = dict()

        while True:
            s = input()
            if s == "CLOSE":
                break

            cmd, name, t = s.split()
            t = int(t)

            if cmd == "ENTER":
                ptime[name] = t
            else:
                if name not in pay:
                    pay[name] = 0
                pay[name] += t - ptime[name]

        print(f"Day {daycnt}")

        for name in sorted(pay):
            print(f"{name} ${pay[name]*0.1:.2f}")

        print()
    except:
        break
