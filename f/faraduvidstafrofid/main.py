def is_vow(c):
    return c in "aeiouAEIOU"
s=input()
vows=[]
vwsi=[]
for i,c in enumerate(s):
    if is_vow(c):
        vows.append(c)
        vwsi.append(i)
ans=list(s)
for i, c in zip(vwsi, vows[::-1]):
    ans[i] = c
print("".join(ans))
