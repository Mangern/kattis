s = input()

rank = 25
star = 0

def gets(x):
    if 21 <= x <= 25:
        return 2
    if 16 <= x <= 20:
        return 3
    if 11 <= x <= 15:
        return 4
    if 1 <= x <= 10:
        return 5
    return 100000000000000

for i, c in enumerate(s):
    if rank == 0:
        continue
    if c == 'W':
        bef = rank
        if star == gets(rank):
            rank -= 1
            star = 0
        star += 1
        if i >= 2 and s[i-2:i+1] == "WWW" and 6 <= bef <= 25:
            if star == gets(rank):
                rank -= 1
                star = 0
            star += 1
    else:
        if rank > 20:
            continue
        if star:
            star -= 1
        elif rank < 20:
            rank += 1
            star = gets(rank) - 1

print(rank if rank else "Legend")

