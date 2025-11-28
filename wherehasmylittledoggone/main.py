ear,leng=map(float,input().split())
rat=ear/leng
n=int(input())
ans=[]
for _ in range(n):
    name=input()
    ratl,rath,elo,ehi=map(float,input().split())
    if ratl <= rat <= rath and elo <= ear <= ehi:
        ans.append(name)

if not ans:
    print("Mutt")
else:
    print("\n".join(ans))
