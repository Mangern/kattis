

val = dict()
val["A"] = (11,11)
val["K"] = (4,4)
val["Q"] = (3,3)
val["J"] = (20,2)
val["T"] = (10,10)
val["9"] = (14,0)
val["8"] = (0,0)
val["7"] = (0,0)

n,dom = input().split()
n = int(n)
n *= 4
ans = 0
for i in range(n):
    line = input()
    c = line[0]
    if line[1] == dom:
        ans += val[c][0]
    else:
        ans += val[c][1]
print(ans)
