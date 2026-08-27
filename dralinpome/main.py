
freq={}
for c in input():
    freq[c] = freq.get(c,0)+1
nodd=0
for v in freq.values():
    if v % 2 == 1:
        nodd += 1
print("yes" if nodd <= 1 else "no")
