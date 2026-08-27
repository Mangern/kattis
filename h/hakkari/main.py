n,m=map(int,input().split())
a = [input() for _ in range(n)]

ans = []
for i in range(n):
    for j in range(m):
        if a[i][j] == '*':
            ans.append((i+1,j+1))

print(len(ans))
for x,y in ans:
    print(x,y)

