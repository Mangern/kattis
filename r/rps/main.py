def beats(a,b):
    if a == 'R':
        return b == 'S'
    if a == 'P':
        return b == 'R'
    if a == 'S':
        return b == 'P'
while True:
    s=input()
    if "E" in s:
        break
    t=input()

    p1 = 0
    p2 = 0
    for a,b in zip(s,t):
        if beats(a,b):
            p1 += 1
        if beats(b,a):
            p2 += 1
    print(f"P1: {p1}\nP2: {p2}")
