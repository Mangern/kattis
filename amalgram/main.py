a=input()
b=input()
freqa={}
freqb={}
for c in a:
    freqa[c] = freqa.get(c, 0) + 1
for c in b:
    freqb[c] = freqb.get(c, 0) + 1
for c in set(a+b):
    print(c*max(freqa.get(c,0),freqb.get(c,0)),end="")
print()
