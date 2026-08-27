lvl=[0,0,-30]

for _ in range(int(input())):
    p,v=input().split()
    v=int(v[1:])
    if p == "ocean":
        lvl[0] += v
    elif p == "oxygen":
        lvl[1] += v
    else:
        lvl[2] += v
print("liveable" if lvl[0] >= 9 and lvl[1] >= 14 and lvl[2] >= 8 else "not liveable")
