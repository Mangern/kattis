from math import log10, ceil
from sys import stdin

# C += C/4

case=1
for line in stdin:
    n=int(line)
    ans=ceil(log10(3)+n*log10(1+1/2))
    print(f"Case {case}:", int(ans))
    case += 1
