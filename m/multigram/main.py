def check(s, c):
    c = "".join(sorted(c))
    n = len(s)
    for i in range(0, n, len(c)):
        if "".join(sorted(s[i:i+len(c)])) != c:
            return False
    return True
s = input()
n = len(s)

for i in range(1, n):
    if n % i == 0 and check(s, s[:i]):
        print(s[:i])
        exit(0)
print(-1)
