n,k=map(int,input().split())
ans = 0
for _ in range(n):
    cnt = {}
    ws = input().split()
    for w in ws:
        if w not in cnt:
            cnt[w] = 0
        cnt[w] += 1
    for w in cnt:
        ans += cnt[w] - 1
print(ans)
