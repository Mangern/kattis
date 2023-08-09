radi = [20 * 20 * (11-p) * (11-p) for p in range(1,11)]

for _ in range(int(input())):
    n = int(input())
    pos = [tuple(map(int,input().split())) for i in range(n)]
    ans = 0
    for x,y in pos:
        d = x * x + y * y
        score = 0
        for i in range(10):
            if radi[i] >= d:
                score = i+1
        ans += score
    print(ans)


