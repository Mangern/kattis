def dst(a,b):
    x1,y1=map(int,a)
    x2,y2=map(int,b)
    return abs(x1-x2)+abs(y1-y2)

s = int(input())
locs = []

while len(locs) < 4:
    s = s + (s//13)+15
    nm = f"{s%100:0>2}"
    if nm not in locs:
        locs.append(nm)


ans = 0
while len(locs):
    x = input()
    ans += 1
    mni = 2000
    for l in locs:
        mni = min(mni, dst(x,l))

    if mni == 0:
        print("You hit a wumpus!")
        locs = [l for l in locs if l != x]
        if not locs:
            break
    mni = 2000
    for l in locs:
        mni = min(mni, dst(x,l))
    print(mni)
print(f"Your score is {ans} moves.")
