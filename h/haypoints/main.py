m,n = map(int,input().split())
score = dict()
for i in range(m):
    w, s = input().split()
    s = int(s)
    score[w] = s


for i in range(n):
    ans = 0
    while True:
        ws = input().strip()
        if ws == ".":
            break
        ws = ws.split(" ")
        for w in ws:
            if w in score:
                ans += score[w]
    print(ans)

