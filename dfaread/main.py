n,c,s,f = map(int, input().split())
alph = input()

fin = set(map(int, input().split()))

trans = {}

for i in range(n):
    dr = list(map(int, input().split()))

    for j, c in zip(dr, alph):
        trans[(i+1, c)] = j

def accepts(st: str):
    cur = s

    for c in st:
        cur = trans[(cur, c)]

    return cur in fin

m = int(input())

for _ in range(m):
    print("accept" if accepts(input()) else "reject")
