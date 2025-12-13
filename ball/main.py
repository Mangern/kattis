n=int(input())
cnt=[0]*n
for _ in range(n//2+1):
    u,v=map(int,input().split())
    cnt[u-1] += 1
    cnt[v-1] += 1
a,b = [i for i in range(n) if cnt[i] == 2]
print(a+1,b+1)
