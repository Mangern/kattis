a,b,c,d = map(int,input().split())
 
ans = []
xs = ['*','+','-','//']
if not b:
    xs.pop()
ys = ['*','+','-','//']
if not d:
    ys.pop()
for x in xs:
    for y in ys:
        lhs = f"{a} {x} {b}"
        rhs = f"{c} {y} {d}"
        if eval(lhs) == eval(rhs):
            ans.append((lhs + " = " + rhs).replace("//","/"))


print("\n".join(ans) if ans else "problems ahead")
