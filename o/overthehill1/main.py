ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "

n = int(input())
mat = [list(map(int,input().split())) for i in range(n)]

s = input()

a = [ALPH.index(c) for c in s]
while len(a) % n != 0:
    a.append(36)


ans = []
for i in range(0, len(a), n):
    vec = a[i:i+n]
    trans = [sum(x * y for x, y in zip(row, vec))%37 for row in mat]
    for c in trans:
        ans.append(ALPH[c])

print("".join(ans))
