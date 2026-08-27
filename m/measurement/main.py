rec = ["th","in","ft","yd","ch","fur","mi","lea"]
rna = ["thou", "inch", "foot", "yard", "chain", "furlong", "mile", "league"]
amo = [1000, 12, 3, 22, 10, 8, 3]

x,a,_,b=input().split()
x=int(x)

if a in rec:
    ia = rec.index(a)
else:
    ia = rna.index(a)

if b in rec:
    ib = rec.index(b)
else:
    ib = rna.index(b)

if ia < ib: 
    for i in range(ia,ib):
        x /= amo[i]
else:
    for i in range(ib,ia):
        x *= amo[i]

print(x)

