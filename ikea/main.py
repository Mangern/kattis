k=int(input())
n=int(input())
name=[""]*n
a=[]
for i in range(n):
    s,w=input().split()
    name[i] = s
    a.append((int(w),i))
a.sort()
take1=n//k
take2=(n+k-1)//k

ltr=sum(t[0] for t in a[:take2])
rtr=sum(t[0] for t in a[take2:take2+take1])
if ltr<rtr:
    print(ltr)
    ans=[name[idx] for w, idx in a[:take2]]
    ans.sort()
    print("\n".join(ans))
else:
    print(sum(t[0] for t in a[:take1]))
    ans=[name[idx] for w, idx in a[:take1]]
    ans.sort()
    print("\n".join(ans))

