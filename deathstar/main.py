n = int(input())
a = [list(map(int,input().split())) for i in range(n)]

for i in range(n):
    x = 0
    for j in range(n):
        x |= a[i][j]
    print(x,end=" ")
print()
