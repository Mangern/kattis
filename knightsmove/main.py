r,c=input()
r=ord(r)-ord('a')
c=ord(c)-ord('1')
neis = [
    (r-2,c-1),
    (r-2,c+1),
    (r-1,c-2),
    (r-1,c+2),
    (r+1,c-2),
    (r+1,c+2),
    (r+2,c-1),
    (r+2,c+1)
]
neis = [(r,c) for r, c in neis if 0 <= r < 8 and 0 <= c < 8]
neis = [f"{chr(ord('a')+r)}{c+1}" for r,c in neis]
print("\n".join(sorted(neis)))
