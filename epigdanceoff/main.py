n,m=map(int,input().split())
a = [input()+"_" for i in range(n)]


ans = 0
for i in range(m+1):
    for j in range(n):
        if a[j][i] != '_':
            break
    else:
        ans += 1

print(ans)
