stk = []
while True:
    op = input()
    if op == "+":
        b,a=stk.pop(),stk.pop()
        stk.append(a+b)
    elif op == "-":
        b,a=stk.pop(),stk.pop()
        stk.append(a-b)
    elif op == "/":
        b,a=stk.pop(),stk.pop()
        stk.append(a//b)
    elif op == "*":
        b,a=stk.pop(),stk.pop()
        stk.append(a*b)
    elif op == "^":
        b,a=stk.pop(),stk.pop()
        stk.append(a**b)
    elif op == "dup":
        stk.append(stk[-1])
    elif op == "print":
        print(stk[-1])
    elif op == "pop":
        stk.pop()
    elif op == "swap":
        b,a=stk.pop(),stk.pop()
        stk.append(b)
        stk.append(a)
    elif op == "quit":
        break
    else:
        stk.append(int(op))

