rest="😎"
leg ="🦵"
arm ="💪"

seq = []
for _ in range(int(input())):
    s=input()
    if "rest" in s:
        seq.append(rest)
    elif "leg" in s:
        seq.append(leg)
    else:
        seq.append(arm)

weeks=[[] for _ in range(5)]
for day in range(31):
    weeks[day // 7].append(seq[day % len(seq)])


for i, week in enumerate(weeks):
    print(i+1, "".join(week))
