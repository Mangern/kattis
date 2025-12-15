n=int(input())
s=input()
bg=1 if s[-1] == 'G' else 0
ba=1 if s[-1] == 'A' else 0
bd=1 if s[-1] == 'D' else 0
a=ba
g=bg
d=bd
for i in range(n-2,-1,-1):
    g+=1 if s[i] == 'G' else 0
    a+=1 if s[i] == 'A' else 0
    d+=1 if s[i] == 'D' else 0
    # g / (a + g) > bg / (ba + bg)

    if g * (ba + bg) > bg * (a + g) or ba + bg == 0:
        ba = a
        bg = g
        bd = d

print(f"{bg}-{ba}")
