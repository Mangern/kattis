n,m=map(int,input().split())
s = [input() for _ in range(n)]

ans = []
for j in range(m):
    for i in range(n):
        if s[i][j] != '.':
            ans.append(s[i][j])
print("".join(ans))
