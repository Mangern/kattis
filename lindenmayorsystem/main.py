n,m=map(int,input().split())
sub = dict()

for i in range(n):
    s = input().split()
    sub[s[0]] = s[2]

s = input()

for i in range(m):
    ns = []
    for a in s:
        if a in sub:
            ns.append(sub[a])
        else:
            ns.append(a)
    s = "".join(ns)

print(s)
