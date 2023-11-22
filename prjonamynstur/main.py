cost = {
    '.': 20,
    'O': 10,
    '\\': 25,
    '/': 25,
    'A': 35,
    '^': 5,
    'v': 22
}
n, m = map(int, input().split())

print(sum(sum(map(lambda c: cost[c], input())) for _ in range(n)))
