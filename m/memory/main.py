s=input()
s=s.lstrip("0")
ans1=1
ans2=0
mod=10**9+9
for p in s.split("1")[::-1]:
    l=len(p)
    ans1,ans2 = ans1+ans2, l*(ans1+ans2) + ans2
    ans1%=mod
    ans2%=mod
print(ans1)
