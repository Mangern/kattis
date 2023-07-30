cnt = {}

while True:
    s = input()
    if s == "***":
        break
    if s not in cnt:
        cnt[s] = 0
    cnt[s] += 1

mx = 0
uniq = False
mxs = ""
for s in cnt:
    if cnt[s] > mx:
        mx = cnt[s]
        uniq = True
        mxs = s
    elif cnt[s] == mx:
        uniq = False

if uniq:
    print(mxs)
else:
    print("Runoff!")

