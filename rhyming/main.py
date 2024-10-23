s = input()
e = int(input())
lsts = [input().split() for _ in range(e)]
for _ in range(int(input())):
    p = input().split()[-1]

    for l in lsts:
        syrm = False
        pyrm = False

        for x in l:
            if s.endswith(x):
                syrm = True
            if p.endswith(x):
                pyrm = True

        if syrm and pyrm:
            print("YES")
            break
    else:
        print("NO")
