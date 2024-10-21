import re
from sys import stdin

def match_parens(s):
    match = [-1 for _ in range(len(s))]
    stk = []

    for i, c in enumerate(s):
        if c == '(':
            stk.append(i)
        elif c == ')':
            m = stk.pop()
            match[m] = i
            match[i] = m
    assert not stk, "Unmatched elements in stack"
    return match

def eat_nxt(s: str, parens: list[int], l: int, r: int) -> tuple[float, int]:
    if s[l] == '-':
        sub, l = eat_nxt(s, parens, l+1, r)
        return (-sub, l + 1)
    if s[l] == '+':
        sub, l = eat_nxt(s, parens, l+1, r)
        return (sub, l + 1)
    match_num = re.match("\d+", s[l:r])
    if match_num is not None:
        return (float(match_num.group()), len(match_num.group()))
    if s[l] == '(': #)
        sub, l = parse(s, parens, l+1, parens[l])
        return (sub, l + 2)
    assert False

def parse(s: str, parens: list[int], l: int, r: int) -> tuple[float, int]:
    ptr = l
    subexprs = []
    while True:
        num, ln = eat_nxt(s, parens, ptr, r)
        ptr += ln
        subexprs.append(num)
        if ptr == r:
            break
        assert s[ptr] in "+-*/"
        subexprs.append(s[ptr])
        ptr += 1

    sumexprs = []

    for s in subexprs:
        if type(s) == float:
            if sumexprs and sumexprs[-1] == "*":
                sumexprs.pop()
                a = sumexprs.pop()
                sumexprs.append(a * s)
            elif sumexprs and sumexprs[-1] == '/':
                sumexprs.pop()
                a = sumexprs.pop()
                sumexprs.append(a / s)
            else:
                sumexprs.append(s)
        else:
            sumexprs.append(s)
    result = sumexprs[0]
    for i in range(1, len(sumexprs), 2):
        if sumexprs[i] == '+':
            result += sumexprs[i+1]
        else:
            result -= sumexprs[i+1]
    return (result, r - l)

for line in stdin:
    s = "".join(c for c in line if c in "0123456789+-*/()")

    # TODO: eval(s)
    print(f"{parse(s, match_parens(s), 0, len(s))[0]:.2f}")
