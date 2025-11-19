s = 0
for _ in range(int(input())):
    a,b,c=input().split()
    if b == "IN":
        s += int(c)
    else:
        s -= int(c)
print("NO STRAGGLERS" if not s else s)
