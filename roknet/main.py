def main():
    stuff = {}
    vals = {}
    outs = []
    def getv(i):
        if i in vals:
            return vals[i]
        vals[i] = stuff[i]()
        return vals[i]
    def gor(i1,i2):
        return lambda: getv(i1) or getv(i2)
    def gand(i1,i2):
        return lambda: getv(i1) and getv(i2)
    def gnot(i1):
        return lambda: not getv(i1)
    for _ in range(int(input())):
        toks=input().split()
        if toks[0] == "INNTAK":
            _, s, v = toks
            if v == "SATT":
                stuff[s] = lambda: True
            else:
                stuff[s] = lambda: False
        elif toks[0] == "UTTAK":
            _, s = toks
            outs.append(s)
        elif toks[0] == "OG":
            _, i1, i2, s = toks
            stuff[s] = gand(i1,i2)
        elif toks[0] == "EDA":
            _, i1, i2, s = toks
            stuff[s] = gor(i1,i2)
        elif toks[0] == "EKKI":
            _, i, s = toks
            stuff[s] = gnot(i)

    for f in outs:
        print(f, "SATT" if stuff[f]() else "OSATT")
main()
