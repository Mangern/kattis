from sys import stdin
lines = []
for line in stdin:
    lines.append(line)
    
i = 0
while i < len(lines):
    domain = lines[i].split()[1:]
    codomain = lines[i+1].split()[1:]
    n = int(lines[i+2])
    i += 3
    mp = [lines[i+j].split(" -> ") for j in range(n)]
    i += n

    dc = dict()
    rv = dict()
    is_func = True
    for k,v in mp:
        if k in dc:
            is_func = False
        dc[k] = v

        if v not in rv:
            rv[v] = []
        rv[v].append(k)

    if not is_func:
        print("not a function")
        continue

    inj = True
    surj = len(rv) == len(codomain) 
    for v in rv:
        if len(rv[v]) > 1:
            inj = False

    if inj and surj:
        print("bijective")
    elif inj:
        print("injective")
    elif surj:
        print("surjective")
    else:
        print("neither injective nor surjective")
