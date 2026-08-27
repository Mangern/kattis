ans=0
muls = [1,2,4,8]
cur = 0
cons=0
for _ in range(int(input())):
    x = int(input())
    if x == 0:
        cons = 0
        cur = max(0, cur - 1)
    else:
        cons += 1
        if cur < 3 and cons == muls[cur+1]:
            cur += 1
            cons = 0
        ans += x * muls[cur]
print(ans)
