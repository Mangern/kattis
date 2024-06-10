import time

tz = {
    "UTC": 0,
    "GMT": 0,
    "BST": 60,
    "IST": 60, 
    "WET": 0,
    "WEST": 60,
    "CET": 60,
    "CEST": 120,
    "EET": 120,
    "EEST": 3 * 60,
    "MSK": 3 * 60,
    "MSD": 4 * 60,
    "AST": -4 * 60,
    "ADT": -3 * 60,
    "NST": -210,
    "NDT": -150,
    "EST": -5 * 60,
    "EDT": -4 * 60,
    "CST": -6 * 60,
    "CDT": -5 * 60,
    "MST": -7 * 60,
    "MDT": -6 * 60,
    "PST": -8 * 60,
    "PDT": -7 * 60,
    "HST": -10 * 60,
    "AKST": -9 * 60,
    "AKDT": -8 * 60,
    "AEST": 10 * 60,
    "AEDT": 11 * 60,
    "ACST": 570, 
    "ACDT": 630,
    "AWST": 8 * 60
}

for _ in range(int(input())):
    toks = input().split()
    tz1, tz2 = toks[-2:]

    tm = 0
    if len(toks) == 3:
        t = toks[0]
        if t == "noon":
            tm = 12 * 60
        elif t == "midnight":
            tm = 0
        else:
            assert False
    else:
        t = toks[0]
        ampm = toks[1].replace(".", "")
        tm = time.strptime(f"{t} {ampm}", "%I:%M %p")
        tm = tm.tm_hour * 60 + tm.tm_min

    tm_utc = (tm - tz[tz1]) % (24 * 60)
    ans = (tm_utc + tz[tz2]) % (24 * 60)

    if ans == 0:
        print("midnight")
    elif ans == 12 * 60:
        print("noon")
    else:
        t = time.gmtime(ans * 60)
        ans = time.strftime("%I:%M %p", t).replace("PM", "p.m.").replace("AM", "a.m.")
        if ans[0] == "0":
            ans = ans[1:]
        print(ans)
