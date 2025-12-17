corr={}
fail={}
n=int(input())
ws=input().split()
for _ in range(int(input())):
    src,dst,status=input().split()
    if src not in corr:
        corr[src] = []
        fail[src] = []
    if status == "correct":
        corr[src].append(dst)
    else:
        fail[src].append(dst)

num_corr=1
num_tot=1
res=[]
for w in ws:
    num_corr *= len(corr[w])
    num_tot *= len(corr[w]) + len(fail[w])
    if not corr[w]:
        res.append(fail[w][0])
    else:
        res.append(corr[w][0])

if num_tot == 1:
    print(" ".join(res))
    print("correct" if num_corr == 1 else "incorrect")
else:
    print(num_corr,"correct")
    print(num_tot-num_corr,"incorrect")
