n=int(input())
bad=set(input() for _ in range(n))
for _ in range(int(input())):
    ok=True
    for i in range(6):
        if input() in bad:
            ok = False
    print("Fínn Stokkur" if ok else "Hæfileikalaust Drasl")
