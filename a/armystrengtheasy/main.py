# Copied from prev solved armystrengthhard

for _ in range(int(input())):
    input()
    ng,nm = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a.sort()
    a.reverse()
    b.sort()
    b.reverse()

    while len(a) and len(b):
        if b[-1] <= a[-1]:
            b.pop()
        else:
            a.pop()

    if len(a):
        print("Godzilla")
    else:
        print("MechaGodzilla")

