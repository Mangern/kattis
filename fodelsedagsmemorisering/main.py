val = dict()
n = int(input())
for i in range(n):
    name,v,d=input().split()
    v = int(v)
    if d not in val:
        val[d] = (0,name)
    if v > val[d][0]:
        val[d] = (v,name)
ans = [val[k][1] for k in val]
ans.sort()
print("\n".join(ans))
