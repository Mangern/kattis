a=set(input())
res=[]
for i in range(26):
    c=chr(ord('a')+i)
    if c not in a:
        res.append(c)
if not res:
    print("Good job!")
else:
    print("".join(res))
