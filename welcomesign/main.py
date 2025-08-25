r, c = map(int, input().split())

fl = False
for _ in range(r):
    s = input()
    l = (c - len(s)) // 2
    r = l
    if l + r != c - len(s):
        if fl:
            l += 1
        else:
            r += 1
        fl = not fl

    print(f"{'.'*l}{s}{'.'*r}")
