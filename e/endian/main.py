def batched(s, c):
    return [s[i:i+c] for i in range(0, len(s), c)]
f,t=input().split()
n=int(input())
s=input()

if f == t:
    print(s)
    exit()

if s[:2] == "0x":
    s = s[:2] + "".join(reversed(batched(s[2:], 2)))
else:
    s = s[:2] + "".join(reversed(batched(s[2:], 8)))
print(s)
