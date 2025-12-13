from sys import stdin
for line in stdin:
    s=line.replace(" ", "").replace("\t", "").replace("\n","")
    print(sum(map(float,s.split(","))))
