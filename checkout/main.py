from itertools import product
moves = [("bullseye", 50), ("single bull", 25)]

for i in range(1, 21):
    moves.append((f"single {i}", i))
    moves.append((f"double {i}", 2*i))
    moves.append((f"triple {i}", 3*i))

reach = {}

for throws in range(1, 4):
    for play in product(sorted(moves), repeat=throws):
        score = sum(move[1] for move in play)
        if score not in reach:
            reach[score] = []
        reach[score].append([move[0] for move in play])

combs = reach.get(int(input()), [])

for c in combs:
    if c[-1].startswith("double") or c[-1] == "bullseye":
        print("\n".join(c))
        break
else:
    print("impossible")
