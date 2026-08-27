def check(a):
    prv = -1
    for s in a:
        if int(s) < prv:
            return True
        prv = int(s)
    return False

n = int(input())
a = input().split()

for i, s in enumerate(a):
    l = list(s)
    for j in range(len(l)):
        c = l[j]

        for d in "0123456789":
            l[j] = d

            a[i] = "".join(l)

            if not a[i].startswith("0") or a[i] == "0":
                if check(a):
                    print(" ".join(a))
                    exit(0)

            l[j] = c

    a[i] = s

print("impossible")
