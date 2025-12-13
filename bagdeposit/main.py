stks=[]
for _ in range(int(input())):
    _,r=map(int,input().split())
    for s in stks:
        if s[-1] > r:
            s.append(r)
            break
    else:
        stks.append([r])
print(len(stks))
