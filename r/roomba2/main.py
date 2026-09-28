n,m=map(int,input().split())

if n == 1:
    ans = [(0, i) for i in range(m)] + [(0, i) for i in range(m-2, -1, -1)]
elif m == 1:
    ans = [(i, 0) for i in range(n)] + [(i, 0) for i in range(n-2, -1, -1)]
elif n == 2:
    ans = [(0, i) for i in range(m)] + [(1, i) for i in range(m - 1, -1, -1)] + [(0,0)]
elif m == 2:
    ans = [(i, 0) for i in range(n)] + [(i, 1) for i in range(n - 1, -1, -1)] + [(0,0)]
elif n % 2 == 0:
    ans = [(i, 0) for i in range(n)]
    for i in range(n - 1, -1, -2):
        for j in range(m - 1):
            ans.append((i, j + 1))
        for j in range(m - 1, 0, -1):
            ans.append((i-1, j))
    ans.append((0,0))
elif m % 2 == 0:
    ans = [(0, i) for i in range(m)]
    for j in range(m - 1, -1, -2):
        for i in range(n - 1):
            ans.append((i + 1, j))
        for i in range(n - 1, 0, -1):
            ans.append((i, j - 1))
    ans.append((0,0))
else:
    ans = [(i, 0) for i in range(n)] + [(n - 1, j) for j in range(1, m)]

    for i in range(n - 2, 1, -2):
        for j in range(m - 1, 0, -1):
            ans.append((i, j))
        for j in range(m - 1):
            ans.append((i-1, j + 1))

    for j in range(m - 1, 0, -2):
        ans.append((1, j))
        ans.append((0, j))
        ans.append((0, j-1))
        ans.append((1, j-1))

    ans.append((1,0))
    ans.append((0,0))


for a, b in ans:
    print(a,b)
