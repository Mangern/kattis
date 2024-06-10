from datetime import datetime
from itertools import permutations

inp = input()
a = inp.split("/")

lst = []

for p in permutations(a):
    y, m, d = p

    while len(y) < 3:
        y = "0" + y

    if len(y) == 3:
        y = "2" + y

    y = int(y)
    m = int(m)
    d = int(d)

    istr = f"{y}-{m:02d}-{d:02d}"

    try:
        dt = datetime.fromisoformat(istr)
        lst.append(dt)
    except:
        pass

if not lst:
    print(f"{inp} is illegal")
else:
    lst.sort()
    ans = lst[0].isoformat()
    ans = ans[:ans.index("T")]
    print(ans)
