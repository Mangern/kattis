def build(n: int):
    s = str(n)
    l = ["-"] * len(s)
    stk = []
    for i, c in enumerate(s):
        if l[i] != "-":
            break
        d = s[len(s)-1-i]
        l[i] = c
        l[len(s) - 1 - i] = c
        if int(c) > 0:
            stk.append(i)
    lst = -1
    while int("".join(l)) > n:
        i = stk.pop()
        ch = str(int(s[i])-1)
        l[i] = ch
        l[len(s)-1-i] = ch
        lst = i

    if lst != -1:
        for i in range(lst + 1, len(s) - 1 - lst):
            l[i] = "9"
            l[len(s) - 1 - i] = "9"


    f = "".join(l)
    assert int(f) <= n
    assert f[::-1] == f

    return f

for k in range(1,101):
    print(k, build(1<<k))
