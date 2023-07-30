res = {}
for i in range(512):
    x = (i ^ (i << 1))
    x = x & ((1<<8)-1)
    if x not in res:
        res[x] = i



n = int(input())

for x in map(int,input().split()):
    print(res[x],end=" ")
print()
