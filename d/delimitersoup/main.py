n = int(input())
s = input()
stack = []

match = {'(': ')', '[': ']', '{': '}'}

for i,c in enumerate(s):
    if c == ' ':
        continue
    if c in match:
        stack.append(c)
        continue

    if len(stack) and match[stack[-1]] == c:
        stack.pop()
    else:
        print(c, i)
        exit(0)

print("ok so far")
