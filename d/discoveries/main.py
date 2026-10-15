def Y():
 print(1);exit()
R=list(range(8))
B=[list(input())for _ in R][::-1]
x,y,z,w=input()
x=ord(x)-ord('a')
y=ord(y)-ord('1')
z=ord(z)-ord('a')
w=ord(w)-ord('1')
B[w][z]=B[y][x]
B[y][x]="_"
kr,kc=next((i,j)for i in R for j in R if B[i][j]=='k')
for p,g in[(p,g)for p in[-1,0,1]for g in[-1,0,1]]:
 for k in R[1:]:
  a,b=kr+k*p,kc+k*g
  if not(a in R and b in R)or(a,b)==(w,z):break
  c=B[a][b]
  if c=='_':continue
  if c in"Q"+" RB"[abs(p)+abs(g)]:Y()
  break
print(0)
