s = input()

for _ in range(int(input())):
    for i,c in enumerate(input()):
        o = ord(c) - ord('A')
        o *= int(s[i])
        o %= 26
        print(chr(o+ord('A')), end="")
    print()

