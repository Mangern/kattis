def fail():
    print("INVALID!")
    exit()
a=[list(map(int,input().split())) for _ in range(9)]

# check rows
for row in a:
    if len(set(row)) != 9:
        fail()
#cols
for j in range(9):
    if len(set(row[j] for row in a)) != 9:
        fail()

# 3x3
for i in range(0,9,3):
    for j in range(0,9,3):
        s = set()
        for ii in range(i,i+3):
            for jj in range(j,j+3):
                s.add(a[ii][jj])
        if len(s) != 9:
            fail()
print("VALID")
