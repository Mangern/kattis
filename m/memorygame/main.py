# Something is wrong with this task...
n,k=map(int,input().split())
prs=0
seen=set()
for i in map(int,input().split()):
    if i in seen:
        prs += 1
    seen.add(i)
if n - prs <= 1:
    print(n)
else:
    print(prs)
