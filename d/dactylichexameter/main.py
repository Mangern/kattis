s = input()
s += " " * 100

i = 0
a = []
while True:
    if s[i:i+2] == "--":
        a.append("s")
        i += 2
    elif s[i:i+3] == "-uu":
        a.append("d")
        i += 3
    elif s[i:i+2] == "-u":
        a.append("t")
        i += 2
    else:
        if s[i] != " ":
            print("no")
            exit()
        break

if len(a) != 6:
    print("no")
else:
    valid = True
    for i in range(5):
        if a[i] not in ["d", "s"]:
            valid = False
    if a[5] not in ["t", "s"]:
        valid = False

    if not valid:
        print("no")
    else:
        print("yes")





