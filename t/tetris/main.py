good = [
    [(0,), (0,0,0,0)],
    [(0,0)],
    [(0,0,1),(1,0)],
    [(1,0,0),(0,1)],
    [(0,0,0),(0,1),(1,0),(1,0,1)],
    [(0,0,0),(0,0),(0,1,1),(2,0)],
    [(0,0,0),(0,2),(1,1,0),(0,0)]
]

c,p=map(int,input().split())
a = list(map(int,input().split()))
p -= 1

ans = 0
for w in good[p]:
    l = len(w)
    win = []
    for i in range(l):
        win.append(a[i])
    for i in range(l,c+1):
        if tuple(x-min(win) for x in win) == w:
            ans += 1
        if i < c:
            win = win[1:] + [a[i]]
print(ans)
