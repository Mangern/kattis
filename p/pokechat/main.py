s = input()
enc = input().strip()

for a,b,c in zip(enc[::3], enc[1::3], enc[2::3]):
    print(s[int(a+b+c)-1], end="")
print()

