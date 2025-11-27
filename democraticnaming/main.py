n,m=map(int,input().split())
g=[input() for _ in range(n)]
for j in range(m):
    cnts = [0]*26
    for s in g:
        cnts[ord(s[j])-ord('a')] += 1

    mx = max(cnts)
    c = cnts.index(mx)
    print(chr(c+ord('a')),end="")
print()
