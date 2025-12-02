r,c=map(int,input().split())
if c == 1:
    print(1)
    exit()

if r>2:
    print(-1)
    exit()

if r == 1:
    print((c + 2) // 3)
else:
    print((c + 2) // 2)
