for _ in range(int(input())):
    s,h=map(int,input().split())
    hatch = [tuple(map(int,input().split())) for i in range(h)]
    
    for x in range(1,s):
        for y in range(1,s):
            imp = False
            mdst = 0
            for hx,hy in hatch:
                dst = (hx-x)*(hx-x)+(hy-y)*(hy-y)
                if dst == 0:
                    imp = True
                    break
                mdst = max(mdst,dst)
            if imp:
                continue
            mnsd = min(x,y,s-x,s-y)
            if mdst <= mnsd * mnsd:
                print(x,y)
                break
        else:
            continue
        break
    else:
        print("poodle")

        
