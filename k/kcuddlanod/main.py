remap=["0","1","5","3","4","2","6","7","8","9"]
a,b=input().split()
a=int("".join(remap[ord(c)-ord('0')] for c in a[::-1]))
b=int("".join(remap[ord(c)-ord('0')] for c in b[::-1]))
print(1 if a>b else 2)
