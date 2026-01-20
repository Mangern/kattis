trans={
    "North": ["North"],
    "West": ["West"],
    "East": ["East"],
    "South": ["South"],
}
stk=[]

for _ in range(int(input())):
    s=input()
    if s.startswith("Move"):
        dir = s.split()[-1]
        print(trans[dir][-1])
        continue
    if s.startswith("Change"):
        f, tmp, to = s.split()[1:]
        trans[f].append(to)
        stk.append(f)
        continue

    num = int(s.split()[4])

    for _ in range(num):
        who = stk.pop()
        trans[who].pop()

