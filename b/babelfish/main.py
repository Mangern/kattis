from sys import stdin
d={}

for line in stdin:
    s = line.strip()
    if s == "":
        break
    a,b=s.split()
    d[b] = a

for line in stdin:
    print(d.get(line.strip(), "eh"))
