a = [1, 0, 6]
for n in range(14):
    a.append((36 * (n + 2) * (n + 1) * a[n] + 24 * (n+2)**2 * a[n+1] + (n + 3) * (n + 2) * a[n+2]) // (n+3)**2)
[print(a[int(input())]) for _ in range(int(input()))]
