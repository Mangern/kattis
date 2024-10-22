def pretty(s, paren_match, l, r, d = 0):
    assert s[l] == '{'#}
    ptr = l
    ind = " "*d
    print(f"{s[l]}")
    if r - l > 1:
        print(ind + "  ", end="")
    ptr += 1
    while ptr < r:
        if s[ptr] == '{':#}
            pretty(s, paren_match, ptr, paren_match[ptr], d + 2)
            ptr = paren_match[ptr]
        else:
            print(f"{s[ptr]}", end = "" if s[ptr] != ',' else ("\n" + " "*(d+2)))
            ptr += 1
    if r - l > 1:
        print("", end="\n" + " "*d)
    else:
        print("", end="" + " "*d)

s = input()
paren_match = [-1 for _ in range(len(s))]
stk = []
for i, c in enumerate(s):
    if c == '{': #}
        stk.append(i)
    elif c == '}':
        m = stk.pop()
        paren_match[m] = i
        paren_match[i] = m

pretty(s, paren_match, 0, len(s) - 1)
print("}")
