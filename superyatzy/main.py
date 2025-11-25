n,m=map(int,input().split())
cnts=[0]*6
for _ in range(n):
    cnts[int(input())-1]+=1
if max(cnts)>= n - m:
    print("Ja")
else:
    print("Nej")
