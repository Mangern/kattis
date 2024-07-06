from itertools import permutations

sidelst = [
    list(map(int, input().split())) 
    for _ in range(3)
]

for sides in permutations(sidelst):
    for rotm in range(8):
        a = [
            (w, h) if (rotm & (1<<i)) else (h, w)
            for i, (h, w) in enumerate(sides)
        ]

        ws, hs = zip(*a)

        if sum(ws) == hs[0] and hs[0] == hs[1] == hs[2]:
            print("YES")
            exit()

        if ws[0] + ws[1] == ws[2] and hs[0] == hs[1] and hs[0] + hs[2] == ws[2]:
            print("YES")
            exit()

print("NO")
exit()
