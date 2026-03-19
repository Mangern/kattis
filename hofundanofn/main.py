nm=input().split()
short=" ".join(f"{s[0]}." for s in nm[:-1])
print(f"{nm[-1]}, {short}" if len(nm) > 1 else nm[0])
