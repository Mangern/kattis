def lowerbound(arr, val):
    lo = 0
    for a,b in arr:
        if a <= val:
            lo = b
    return lo

n = int(input())
cp = []
days = set()
for i in range(n):
    k = int(input())
    cp.append([])
    for j in range(k):
        x,d=map(int,input().split())
        cp[-1].append((d,x))
        days.add(d)
    cp[-1].sort()



for d in sorted(days):
    sm = sum(lowerbound(c,d) for c in cp)
    print(sm, end=" ")
print()
