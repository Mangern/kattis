t,b =map(int,input().split())
bs = list(map(int,input().split()))

ver = {}
for i in range(t):
    s,v=input().split()
    ver[s] = int(v)

for x in bs:
    sm = 0
    for i in range(x):
        s,v=input().split()
        sm += ver[s] - int(v)
    print(sm)
