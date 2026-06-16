m = int(input())

minbr = float('inf')

for w in range(10 * 60 + 1):
    br = 0 if w <= 6 * 60 else 30 if w <= 9 * 60 else 45
    br = max(br, m - w)
    if w + br > m:
        continue

    minbr = min(minbr, br)

print(minbr)
