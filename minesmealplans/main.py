plan={
    "Marble": (19, 200),
    "Marble+": (19, 350),
    "Quartz": (14, 200),
    "Quartz+": (14,350)
}

for _ in range(int(input())):
    a, k, sw, mon = input().split()
    sw=int(sw)
    mon=float(mon)

    stot, mtot = plan[k]

    y = stot-sw
    z = mtot -mon

    if y>0 and z>0:
        print(f"{a} {y} {z:.2f} Use meal swipe or munch money")
    elif z>0:
        print(f"{a} {y} {z:.2f} Use munch money")
    elif y>0:
        print(f"{a} {y} {z:.2f} Use meal swipe")
    else:
        print(f"{a} {y} {z:.2f} Go to Downtown Golden!")
