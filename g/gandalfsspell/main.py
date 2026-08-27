s = input()
a = input().split()

if len(s) != len(a):
    print("False")
    exit(0)


mp = {}
mpc = {}
for c, word in zip(s, a):
    if word not in mp and c not in mpc:
        mp[word] = c
        mpc[c] = word
    elif word not in mp or mp[word] != c:
        print("False")
        exit(0)
    elif c not in mpc or mpc[c] != word:
        print("False")
        exit(0)
print("True")
