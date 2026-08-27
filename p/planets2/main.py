live={}
n=int(input())
ans={}

plans=[]
for _ in range(n):
    toks=input().split()
    plan=toks[0]
    for i in range(2, len(toks)):
        live[toks[i]] = plan
    plans.append(plan)

for _ in range(int(input())):
    a,b=input().split()
    p=live[b]
    ans[p]=ans.get(p, 0) + int(a)
for p in sorted(plans):
    print(p, ans.get(p, 0))
