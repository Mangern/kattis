n, m = map(int,input().split())
a = list(map(lambda x: int(x)-1,input().split()))

bl = [0 for i in range(n)]
for x in a:
    bl[x] = 1

def out(pair):

    if pair[0] != pair[1]:
        print(f"{pair[0]+1}-{pair[1]+1}", end="")
    else:
        print(pair[0]+1,end="")


er = []
co = []

i = 0
while i < n:
    j = i
    while j < n and bl[j] == bl[i]:
        j += 1

    if bl[i]:
        er.append((i,j-1))
    else:
        co.append((i,j-1))
    i = j

print("Errors: ", end="")
if len(er) >= 2:
    for p in er[:-2]:
        out(p)
        print(",", end=" ")

    out(er[-2])
    print(" and ", end="")
out(er[-1])
print()

print("Correct: ", end="")
if len(co) >= 2:
    for p in co[:-2]:
        out(p)
        print(",", end=" ")

    out(co[-2])
    print(" and ", end="")
out(co[-1])
print()
