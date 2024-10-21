def is_num(s):
    try:
        int(s)
        return True
    except:
        return False

def is_op(s):
    return s in ["+", "-", "*"]

def parse(lst):
    stack = []

    for el in lst:
        stack.append(el)
        while len(stack) >= 3 and is_num(stack[-1]) and is_num(stack[-2]) and is_op(stack[-3]):
            b = int(stack.pop())
            a = int(stack.pop())
            op = stack.pop()

            res = 0
            if op == '+':
                res = a + b
            elif op == '-':
                res = a - b
            else:
                res = a * b
            stack.append(str(res))
    return " ".join(stack)

import sys
for i, line in enumerate(sys.stdin):
    print(f"Case {i+1}:", parse(line.split()))
