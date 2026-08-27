input()
n = int(input())

alts = [
    input().strip().split(", ")
    for _ in range(n)
]

congo = [0] * n

for i in range(n):
    for j in range(n):
        if i != j:
            change = sum(1 for x, y in zip(alts[i], alts[j]) if x != y)
            congo[i] = max(congo[i], change)

mini = min(congo)

for s, c in zip(alts, congo):
    if c == mini:
        print(", ".join(s))
