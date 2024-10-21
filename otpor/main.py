n = int(input())
R = [0] + list(map(float, input().split()))

s = input()

paren = [-1] * len(s)
stk = []
for i, c in enumerate(s):
    if c == '(':
        stk.append(i)
    elif c == ')':
        m = stk.pop()
        paren[m] = i
        paren[i] = m

def parse(s, l, r):
    ptr = l
    r_vals = []
    op = None
    while ptr < r:
        if s[ptr] == ')':
            ptr += 1
            continue
        if s[ptr] == 'R':
            idx = int(s[ptr+1])
            r_vals.append(R[idx])
            ptr += 2
        elif s[ptr] == '(': #)
            r_vals.append(parse(s, ptr + 1, paren[ptr]))
            ptr = paren[ptr] + 1
        else:
            op = s[ptr]
            ptr += 1
    if op is None:
        return r_vals[0]
    if op == '-':
        return sum(r_vals)
    else:
        sm = sum(1/r for r in r_vals)
        return 1 / sm

print(f"{parse(s, 0, len(s)):.6f}")
