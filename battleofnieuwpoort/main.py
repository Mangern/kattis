def tob(x, b):
    ret=[]
    while x > 0:
        ret.append(x%b)
        x //= b
    return ret
def tos(x):
    if x <10:
        return str(x)
    return chr(ord('a')+x-10)
y=int(input().split()[0])

for b in range(2,17):
    ret=tob(y,b)
    if len(ret)>1 and ret[0] == ret[1] == 0:
        print(b, "".join(map(tos,ret[::-1])))
        exit()
print("impossible")
