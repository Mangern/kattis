def heur(l,r):
    if l == r:
        return 3 * l
    if l == r + 1:
        return l + r
    if l == r + 2:
        return 3 * (l - 1)
    return 2 * (l + r)
l,r=map(int,input().split())
print(heur(l,r))
