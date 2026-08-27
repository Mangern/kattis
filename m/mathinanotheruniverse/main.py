from math import floor
toks=input().split()

ntoks=[]

i = 0
while i < len(toks):
    tok = toks[i]
    if tok in "+-":
        a = ntoks.pop()
        b = float(toks[i+1])
        if tok == "+":
            ntoks.append(a+b)
        else:
            ntoks.append(a-b)
        i += 2
        continue
    elif tok in "*/":
        ntoks.append(tok)
        i += 1
        continue
    else:
        ntoks.append(float(tok))
        i += 1
        continue

ret = eval("".join(map(str,ntoks)))
print(int(floor(ret)))
