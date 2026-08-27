t,s,n=map(int,input().split())
a = list(map(int,input().split()))
tp = 0
lw = s
a.append(t)
for x,y in zip(a,a[1:]):
    tp,lw=lw,tp
    m = min(tp,y-x)
    tp -= m
    lw += m
print(tp)
