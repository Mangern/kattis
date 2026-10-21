n,d=map(int,input().split())
a=[]
for _ in range(n):
    v,s=map(int,input().split())
    s=min(s,d)
    t=s/v+(d-s)/(v/2)
    a.append(t)
print(a.index(min(a)))
