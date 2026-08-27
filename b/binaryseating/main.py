cnt = [0] * 1001
n=int(input())
for t in map(int, input().split()):
    cnt[t] += 1

p=1.0
ans=0.0
for i in range(1000, -1, -1):
    m = (1.0/2**cnt[i])
    ans += i * p * (1.0 - m)
    p *= m
print(ans)

