n=int(input())
toks = input().split()
M=10**9+7

depth = 0
stk=[0]
for tok in toks:
    if tok == '(':
        depth += 1
        stk.append(depth % 2)
    elif tok == ')':
        depth -= 1
        x = stk.pop()
        if depth % 2 == 0:
            stk[-1] += x
        else:
            stk[-1] *= x
    else:
        x = int(tok)
        if depth % 2 == 0:
            stk[-1] += x
        else:
            stk[-1] *= x

    stk[-1] %= M
print(stk[-1]%M)
