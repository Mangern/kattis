ciph = input()
key = input()

ans = [] 

for i in range(len(ciph)):
    x = ord(ciph[i]) - ord("A")
    if i < len(key):
        k = ord(key[i]) - ord("A")
    else:
        k = ord(ans[i-len(key)]) - ord("A")
    x += 26 - k
    x %= 26
    x += ord("A")
    ans.append(chr(x))
print("".join(ans))

