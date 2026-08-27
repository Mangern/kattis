from itertools import permutations

def is_valid(day, mo, yr):
    if yr < 2000:
        return False
    if mo > 12 or mo == 0:
        return False

    if mo in [1,3,5,7,8,10,12]:
        return 1 <= day <= 31
    elif mo != 2:
        return 1 <= day <= 30
    else:
        is_leap = 0 
        if yr % 400 == 0:
            is_leap = 1
        elif yr % 100 == 0:
            is_leap = 0
        elif yr % 4 == 0:
            is_leap = 1

        return 1 <= day <= 28+is_leap




for _ in range(int(input())):
    s = "".join(input().split())
    s = "".join(sorted(s))


    vis = set()
    ans = 0
    mini = None
    for tup in permutations(s):
        dat = "".join(tup)
        if dat in vis:
            continue
        vis.add(dat)

        day = int(dat[0]+dat[1])
        mo  = int(dat[2]+dat[3])
        yr  = int(dat[4:])

        if is_valid(day,mo,yr):
            ans += 1
            if mini is None or (yr, mo, day) < mini:
                mini = (yr, mo, day)
    if mini is not None:
        yr,mo,day = mini
        print(ans, f"{day:02} {mo:02} {yr}")
    else:
        print(0)
