s = input()

for k in range(1,len(s)+1):
    if len(s) % k != 0:
        continue

    a = s[:k]
    b = ""
    while len(b) < len(s):
        b += a
        a = a[-1]+a[:-1]

    if b == s:
        print(k)
        break
