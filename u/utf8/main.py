def inv():
    print("invalid")
    exit(0)

n = int(input())
a = [input() for i in range(n)]

i = 0
t = [0 for i in range(4)]
while i < n:
    if a[i].startswith("0"):
        t[0] += 1
        i += 1
    elif a[i].startswith("110"):
        if i+1 >= n or not a[i+1].startswith("10"):
            inv()
        t[1] += 1
        i += 2
    elif a[i].startswith("1110"):
        if i+2 >= n or not a[i+1].startswith("10") or not a[i+2].startswith("10"):
            inv()
        t[2] += 1
        i += 3
    elif a[i].startswith("11110"):
        if i+3 >= n or not a[i+1].startswith("10") or not a[i+2].startswith("10") or not a[i+3].startswith("10"):
            inv()
        t[3] += 1
        i += 4
    else:
        inv()

print("\n".join(map(str,t)))
