from math import inf
n = int(input())
cats = 0

vids = []
for i in range(n):
    t, s = input().split()
    t = int(t)
    bits = 0
    for c in s:
        j = ord(c) - ord('a')
        bits |= (1<<j)
        cats |= (1<<j)
    vids.append((t,bits))

dp = [[None for i in range(1<<10)] for j in range(n)]


def search(s = 0, bits = 0):
    if bits == cats:
        return 0
    if s == n:
        return inf
    if dp[s][bits] != None:
        return dp[s][bits]
    dp[s][bits] = min(search(s+1, bits),  vids[s][0] + search(s+1, bits | vids[s][1]))
    return dp[s][bits]

print(search())
