from math import log

def same(x, y):
    return abs(x-y)<10**-9

sa,sb,sc,sd,sk=input().split()
a=int(sa)
b=float(sb)
c=float(sc)
d=float(sd)
k=int(sk)
ans_x = 0
ans_k = 0

water = log(a, b)
if d < water:
    ans_x = water
    ans_k = 0
elif same(water, d):
    if k >= 0:
        ans_x = water
        ans_k = k + 1
    elif k == -1:
        ans_x = water
        ans_k = None
    else:
        ans_x = water
        ans_k = 0
else:
    # assert(regularity cond)
    ans_x = d
    ans_k = k

ans=[]
if same(ans_x, 0.0):
    pass
elif same(ans_x, 1.0):
    ans.append("n")
elif same(ans_x, round(ans_x)):
    ans.append(f"n^{int(round(ans_x))}")
else:
    p=round(ans_x*10)/10
    ans.append(f"n^{p}")

if ans_k is None:
    ans.append("log log n")
elif ans_k == 1:
    ans.append("log n")
elif ans_k != 0:
    ans.append(f"log^{ans_k} n")

print(" ".join(ans))
