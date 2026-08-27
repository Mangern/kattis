n=int(input())
freq={}
for _ in range(10*n):
    nums=map(int,input().split())
    for x in nums:
        freq[x] = freq.get(x, 0) + 1
ans=[k for k in freq if freq[k] > 2 * n]
if not ans:
    print(-1)
else:
    print(" ".join(map(str, sorted(ans))))
