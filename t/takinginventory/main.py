cnt={}
for _ in range(int(input())):
    w,c=input().split()
    if w not in cnt:
        cnt[w] = 0
    cnt[w] += int(c)

for k in cnt:
    print(k, (cnt[k]+63)//64)
