n = int(input())
c=0
for _ in range(n):
    t,a=map(int,input().split())
    if t == 0:
        c += a
    else:
        c -= min(c,a)
print(c)
