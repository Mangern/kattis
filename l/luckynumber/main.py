lucky=list(range(1,10))
dp = [9]
for d in range(1, 1001):
    dp.append(len(lucky))
    nlucky=[]
    for x in lucky:
        for nxt in range(0, 10):
            y = (x * 10 + nxt)
            if y % (d + 1) == 0:
                nlucky.append(y)
    lucky = nlucky

print(dp[int(input())])
