s = input()
k = int(input())
n = len(s)

ans = n
for ci in range(26):
    tor = [i for i, c in enumerate(s) if ord(c) - ord('a') != ci]
    i = 0
    cur = 0
    while i < len(tor):
        j = i
        while j < len(tor) and tor[j] - tor[i] < k:
            j += 1
        i = j
        cur += 1
    ans = min(ans, cur)
print(ans)
