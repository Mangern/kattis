# p
# AApqArs
def check(s, vals):
    stk = []
    for op in s[::-1]:
        if op in "pqrst":
            stk.append(vals[op])
        elif op == 'N':
            stk.append(1-stk.pop())
        elif op == 'K':
            stk.append(stk.pop() & stk.pop())
        elif op == 'A':
            stk.append(stk.pop() | stk.pop())
        elif op == 'C':
            stk.append(1 if (stk.pop(),stk.pop()) != (1,0) else 0)
        elif op == 'E':
            stk.append(1 if stk.pop()==stk.pop() else 0)

    return stk[0]
while True:
    s = input()
    if s == "0":
        break

    for mask in range(32):
        vals = {k: bool(mask&(1<<i)) for k, i in zip("pqrst", range(5))}
        if not check(s, vals):
            print("not")
            break
    else:
        print("tautology")
