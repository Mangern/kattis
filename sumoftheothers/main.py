from sys import stdin

for line in stdin:
    xs = list(map(int,line.split()))
    s = sum(xs)
    for x in xs:
        if s - x == x:
            print(x)
            break
