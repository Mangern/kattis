b=int(input())
ds=input().split()
s=input()
i = 0
digs=[]
while i < len(s):
    for dig,d in enumerate(ds):
        if s[i:].startswith(d):
            digs.append(dig)
            i += len(d)
            break
ans=0
for i,d in enumerate(digs):
    ans += d * b**(len(digs)-1-i)
print(ans)
