n, k = map(int, input().split())
cmds = input().split()

i = 0
stk = [0]
for _ in range(k):
    if cmds[i] == "undo":
        t = int(cmds[i+1])
        for j in range(t):
            if len(stk) == 1:
                break
            stk.pop()
        i += 2
    else:
        t = int(cmds[i])
        stk.append((stk[-1] + t)%n)
        i += 1

print(stk[-1])
