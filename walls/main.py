from itertools import combinations

l, w, n, r = map(int, input().split())

pts = [tuple(map(int, input().split())) for _ in range(n)]

for cnt in range(1, 5):
    poss = False

    for combo in combinations(pts, cnt):
        walls = [(-l/2,0), (l/2, 0), (0, -w/2), (0, w/2)]
        for px, py in combo:
            walls = [
                (x, y) for x, y in walls
                if (x - px)**2 + (y - py)**2 > r*r
            ]
        
        if not walls:
            print(cnt)
            exit()

print("Impossible")
