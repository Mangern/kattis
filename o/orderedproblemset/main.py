n = int(input())
a = [int(input()) for _ in range(n)]

ans = []

for k in range(2, n+1):
    if n % k != 0:
        continue

    sec = {}
    for p in range(1, n + 1):
        s = (k * p + n - 1) // n
        if s not in sec:
            sec[s] = []
        sec[s].append(a[p-1])

    works = True

    for k, v in sec.items():
        for k1, v1 in sec.items():
            if k1 > k:
                if min(v1) < max(v):
                    works = False
    if works:
        ans.append(k)

print("\n".join(map(str, ans)) if ans else -1)
