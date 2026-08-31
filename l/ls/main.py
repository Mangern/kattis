import re
pat=input()
pat=pat.replace(".", "\\.")
pat=pat.replace("*", ".*")
pat=re.compile(pat)
ans=[]
for _ in range(int(input())):
    s=input()
    if re.fullmatch(pat, s):
        ans.append(s)
print("\n".join(ans))
