nr=[0,0,0]
nc=[0,0,0]
nri=[0,0,0]
nci=[0,0,0]

for _ in range(int(input())):
    s=input()
    addn=nr if s[0] == 'Y' else nc
    addi=nri if s[0] == 'Y' else nci

    for i,c in enumerate(s[1:]):
        addn[i] += 1
        if c == 'Y':
            addi[i] += 1


for i in range(3):
    if nri[i] / nr[i] >= nci[i] / nc[i]:
        print("Not Effective")
        continue
    eff = 100 * (nci[i] / nc[i] - nri[i] / nr[i]) / (nci[i] / nc[i])
    print(eff)
