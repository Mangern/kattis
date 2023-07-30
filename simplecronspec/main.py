def parse_token(token, type):
    if token == '*':
        if type == 'h':
            return [i for i in range(24)]
        return [i for i in range(60)]
    vals = token.split(",")
    ret = []
    for v in vals:
        if "-" in v:
            lo,hi=map(int,v.split("-"))
            for i in range(lo,hi+1):
                ret.append(i)
        else:
            ret.append(int(v))
    return ret


def parse(spec):
    toks = spec.split()

    hrs = parse_token(toks[0], 'h')
    mns = parse_token(toks[1], 'm')
    scs = parse_token(toks[2], 's')

    times = []
    for h in hrs:
        for m in mns:
            for s in scs:
                times.append(h*60*60+m*60+s)
    return times

n = int(input())
secs = [0 for i in range(24*60*60)]
for _ in range(n):
    spec = input()
    times = parse(spec)
    for t in times:
        secs[t] += 1
print(len([s for s in secs if s]), sum(secs))

