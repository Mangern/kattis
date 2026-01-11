stk=[]
for tok in input().split():
    if tok in "+-*/":
        b = stk.pop()
        a = stk.pop()
        stk.append(f"({a}{tok}{b})")
    else:
        stk.append(tok)
print(stk[-1])
