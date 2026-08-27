from math import lcm
from sys import stdin
for line in stdin:
    print(lcm(*map(int, line.split())))
