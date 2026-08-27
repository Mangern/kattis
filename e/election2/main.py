n=int(input())
part={}
for _ in range(n):
    name=input()
    party=input()
    part[name]=party

vote={}
m = int(input())
for _ in range(m):
    name=input()
    if name not in part:
        continue
    if name not in vote:
        vote[name] = 0
    vote[name] += 1

if not vote:
    print("tie")
    exit()

bestv=max(vote.values())
ks=[]
for k in vote:
    if vote[k] == bestv:
        ks.append(k)
if len(ks)>1:
    print("tie")
else:
    print(part[ks[0]])
