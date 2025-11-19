s = "qwertyuiopasdfghjklzxcvbnm"

input()
for c in input():
    if c == ' ':
        print(c,end="")
    else:
        print(s[ord(c)-ord('a')],end="")
print()
