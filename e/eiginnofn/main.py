smut = set()
nsm = dict()
for _ in range(int(input())):
    l = input().split()
    if len(l) == 1:
        smut.add(l[0])
    else:
        nsm[l[0]] = " ".join(l)

for _ in range(int(input())):
    a = input()
    if a in smut:
        print("Jebb")
    elif a not in nsm:
        print("Neibb")
    else:
        print(f"Neibb en {nsm[a]} er heima")


