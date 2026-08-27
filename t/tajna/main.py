def get_r(n):
    r = 1
    i = 1
    while i * i <= n:
        if n%i==0:
            r=i
        i += 1
    return r
s = input()
n = len(s)
r = get_r(n)

c = n // r
grid = [[s[i*r+j] for i in range(c)] for j in range(r)]
for j in range(r):
    for i in range(c):
        print(grid[j][i],end="")
print()
