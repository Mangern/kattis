n,m=map(int,input().split())
items=[input() for _ in range(n)]
ans={}
for i, s in enumerate(items):
    ans[s] = "stolen!"

for i in range(m):
    s=input()
    ans[s] = i + 1
for k in items:
    print(ans[k])
