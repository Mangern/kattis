cnt=[0]*10
ans=-1
for a in map(int,input().split()):
    a %= 10
    cnt[a] += 1
    if cnt[a] == 10:
        ans = a
print(ans if ans != 0 else 10)
