while True:
    nx,ny,w=input().split()
    nx,ny=map(int,(nx,ny))
    w = float(w)
    if nx+ny==0:
        break
    xs = list(map(float,input().split()))
    xs.sort()
    ys = list(map(float,input().split()))
    ys.sort()

    xseg = []
    for x in xs:
        xseg.append((x-w/2,x+w/2))

    fail = False
    for a,b in zip(xseg,xseg[1:]):
        if b[0] > a[1]:
            fail = True

    if fail or xseg[0][0] > 0.0 or xseg[-1][1] < 75.0:
        print("NO")
        continue


    yseg = []
    for y in ys:
        yseg.append((y-w/2,y+w/2))

    fail = False
    for a,b in zip(yseg,yseg[1:]):
        if b[0] > a[1]:
            fail = True

    if fail or yseg[0][0] > 0.0 or yseg[-1][1] < 100.0:
        print("NO")
        continue
    print("YES")
