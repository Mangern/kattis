ps=[]
ws=[]
for _ in range(int(input())):
    k,m,w=map(int,input().split())
    ws.append(w)
    ps.append(k*m)
ws.sort()
ps.sort()
print(sum(a*b for a,b in zip(ps,ws)))
