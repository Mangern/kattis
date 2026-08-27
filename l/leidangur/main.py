stk=[]
fail = False
for c in input():
    if c == '.':
        continue
    if c == 'p' or c == 'g' or c == 'o':
        stk.append(c)
    else:
        while len(stk) > 0 and stk[-1] != c.lower():
            stk.pop()
        if not len(stk):
            fail = True
        if len(stk) > 0 and stk[-1] == c.lower():
            stk.pop()
if fail:
    print("Neibb")
else:
    print(sum(1 for c in stk if c == 'p'))
    print(sum(1 for c in stk if c == 'g'))
    print(sum(1 for c in stk if c == 'o'))
