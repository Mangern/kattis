from sys import stdin
for line in stdin:
    r,s=map(float, line.split())
    v=(r*(s+0.16)/0.067)**0.5
    print(round(v))
