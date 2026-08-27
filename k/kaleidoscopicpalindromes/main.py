def check(x, j):
    a = []
    pw = 1
    while pw <= x:
        pw *= j

    pw //= j

    while pw:
        d = x // pw
        x -= d * pw
        a.append(d)
        pw //= j
    return a == a[::-1]


a, b, k = map(int, input().split())

nums = [i for i in range(a, b+1)]

#print("To check:", len(nums))

ans = 0
for x in nums:
    for j in range(2, k+1):
        if not check(x, j):
            break
    else:
        ans += 1
print(ans)
