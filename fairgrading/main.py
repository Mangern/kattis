from math import floor
a,b,c=map(int,input().split())
s=a+b+c * 2
if s >= 90*4:
    print("A")
elif s >= 80*4:
    print("B")
elif s >= 70*4:
    print("C")
elif s >= 60*4:
    print("D")
else:
    print("F")
