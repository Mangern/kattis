n = int(input())
s = [input() for i in range(n)]

sm = [0 for i in range(max(map(len,s)))]
nm = [0 for i in range(len(sm))]

for a in s:
    for i,c in enumerate(a):
        nm[i] += 1
        sm[i] += ord(c)

for a,b in zip(sm,nm):
    print(chr(a//b),end="")
print()
