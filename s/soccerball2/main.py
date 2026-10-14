from sys import stdin
occ   = {}
for line in stdin.read().splitlines():
    a, b = map(int, line.split())
    if not 1 <= a <= 60 or not 1 <= b <= 60 or a == b:
        continue
    occ[a] = occ.get(a, 0) + 1
    occ[b] = occ.get(b, 0) + 1
for i in range(1,61):
    if occ.get(i, 0) < 3:
        print("No")
        exit()
print("Yes")
