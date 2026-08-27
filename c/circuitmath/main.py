from inspect import signature
n = int(input())

op = {
    '*': lambda a,b: a and b,
    '+': lambda a,b: a or b,
    '-': lambda a: not a
}

inp = [True if c == 'T' else False for c in input().split()]

stack = []

for c in input().split():
    if c in op:
        nargs = len(signature(op[c]).parameters)
        args = [stack.pop() for i in range(nargs)]
        stack.append(op[c](*args))
    else:
        stack.append(inp[ord(c) - ord('A')])

print('T' if stack[-1] else 'F')

