from sys import stdin

vals = {}
rvals = {}

for line in stdin.readlines():
    toks = line.split()
    if toks[0] == "def":
        var = toks[1]
        val = int(toks[2])

        if var in vals:
            del rvals[vals[var]]
        vals[var] = val
        rvals[val] = var

    elif toks[0] == "calc":
        zlst = ["+"] + toks[1:-1]
        res = 0

        print(line[line.find(" ")+1:-1], end=" ")

        for op, var in zip(zlst[::2], zlst[1::2]):
            if var not in vals:
                print("unknown")
                break
            if op == "+":
                res += vals[var]
            else:
                res -= vals[var]
        else:
            print(rvals.get(res, "unknown"))

    else:
        assert toks[0] == "clear"
        vals.clear()
        rvals.clear()
