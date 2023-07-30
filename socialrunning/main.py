n = int(input())
dst = [int(input()) for i in range(n)]

ans = max(*dst)*4+8
for i in range(n):
    cur = dst[i] + dst[(i-2+n)%n]
    ans = min(ans,cur)
print(ans)
