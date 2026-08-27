def cnt(s):
    return sum(1 for c in s if c != ' ')
for _ in range(int(input())):
    n=int(input())
    bnd=input()
    cb=cnt(bnd)
    a=[input() for _ in range(n)]
    a = [s for s in a if cnt(s) == cb]
    a.sort()
    print(f"{bnd}:")
    print("\n".join(a))
