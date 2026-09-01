n=int(input())
a=list(map(int,input().split()))
pf=[a[0]]
for x in a[1:]:
    pf.append(pf[-1]+x)
if pf[-1] < 0:
    print("-INFINITY")
elif pf[-1] > 0:
    print("INFINITY")
else:
    print(sum(pf)/n)
