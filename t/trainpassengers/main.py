c, n = map(int, input().split())
ans = True
cur = 0
for i in range(n):
    left, enter, wait = map(int, input().split())
    if left > cur:
        ans = False
    cur -= left
    cur += enter
    if cur > c:
        ans = False

    if wait > 0 and (cur < c or i == n - 1):
        ans = False

    if i == n - 1 and (enter > 0 or cur > 0):
        ans = False


print("possible" if ans else "impossible")
