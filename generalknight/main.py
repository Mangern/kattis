cs = "abcdefgh"
a,b=map(int, input().split())
s=input()
row=cs.index(s[0])
col=int(s[1])-1

ans=[]
for i in range(8):
    for j in range(8):
        if abs(i-row)==a and abs(j-col)==b or abs(i-row)==b and abs(j-col)==a:
            ans.append(cs[i] + str(j+1))

ans.sort()
print(len(ans))
print(" ".join(ans))
