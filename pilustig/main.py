from itertools import product
moves = [("Bullseye", 50), ("Outer bullseye", 25)]

for i in range(1, 21):
    moves.append((f"Single {i}", i))
    moves.append((f"Double {i}", 2*i))
    moves.append((f"Triple {i}", 3*i))

reach = {}

for throws in range(1, 4):
    for play in product(sorted(moves), repeat=throws):
        score = sum(move[1] for move in play)
        if score not in reach:
            reach[score] = []
        reach[score].append([move[0] for move in play])

combs = reach.get(int(input()), [])

print(len(combs))

for c in combs:
    print(len(c))
    print("\n".join(c))
