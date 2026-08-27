s=input()
t=input()
n=len(s)
ans=["-"]*n

cnt1={}
cnt2={}

for c in s:
    if c not in cnt1:
        cnt1[c] = 0
    cnt1[c] += 1
for c in t:
    if c not in cnt2:
        cnt2[c] = 0
    cnt2[c] += 1

for i in range(n):
    if s[i] == t[i]:
        cnt1[s[i]] -= 1
        cnt2[s[i]] -= 1
        ans[i] = 'G'

for i in range(n):
    if ans[i] != '-':
        continue
    if t[i] in cnt1 and cnt1[t[i]] > 0:
        ans[i] = 'Y'
        cnt1[t[i]] -= 1
print("".join(ans))
