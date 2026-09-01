n=int(input())
a=[input() for _ in range(n)]
base=[s.replace("0", "D").replace("8", "B") for s in a]
mx=sum(int(x,16) for x in base)
mn=0
for s in base:
    t = s.replace("D", "0").replace("B", "8")
    if t[0] == "0" and len(t) > 1:
        t = "D" + t[1:]
    mn += int(t, 16)
print(f"{mx:X}")
print(f"{mn:X}")
