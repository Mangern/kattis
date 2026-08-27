ans = ""
ansi = 0
for _ in range(int(input())):
    w, n, t = input().split()
    n = int(n); t = int(t)
    if (n + 1) * t > ansi:
        ansi = (n + 1) * t
        ans = w

print(ans, ansi)
