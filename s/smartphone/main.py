def pure(s, goal):
    i = 0
    for a,b in zip(s,goal):
        if a != b:
            break
        i += 1
    return len(s) - i + len(goal) - i

for _ in range(int(input())):
    goal = input()
    a,b,c,d = [input() for _ in range(4)]
    print(min(
        pure(a,goal),
        1 + pure(b,goal),
        1 + pure(c,goal),
        1 + pure(d,goal)
    ))

