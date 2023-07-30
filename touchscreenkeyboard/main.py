keyb = [
    "qwertyuiop",
    "asdfghjkl ",
    "zxcvbnm   "
]

pos = {}

for row,s in enumerate(keyb):
    for col,c in enumerate(s):
        if c != " ":
            pos[c] = (row,col)

dist = {}

alpha = list(map(lambda x: chr(x+ord('a')), range(26)))

for a in alpha:
    for b in alpha:
        dist[(a,b)] = abs(pos[a][0]-pos[b][0])+abs(pos[a][1]-pos[b][1])


def wdist(x,y):
    return sum(dist[(a,b)] for a,b in zip(x,y))

for _ in range(int(input())):
    s,n=input().split()
    n = int(n)

    ws = [input() for i in range(n)]
    ws.sort(key=lambda x: (wdist(s,x),x))
    print("\n".join(f"{x} {wdist(s,x)}" for x in ws))
