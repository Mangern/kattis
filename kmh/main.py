highest = 0
for _ in range(int(input())):
    s = input()
    if s == "/":
        lim = ((highest // 10) + 1) * 10
        print(lim)
    else:
        n = int(s)
        highest = max(highest, n)
        print(n)
