n,m=map(int,input().split())
pos = [i for i in range(n)]

for i in range(m):
    a = int(input())-1
    pos[a],pos[a+1]=pos[a+1],pos[a]

print("\n".join(str(x+1) for x in pos))
