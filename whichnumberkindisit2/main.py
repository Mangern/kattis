def isq(x):
    s = round(x**0.5)
    return (s-1)**2 == x or s**2 == x or (s+1)**2 == x
for _ in range(int(input())):
    x=int(input())
    s = ""
    if x & 1:
        s += "O"
    if isq(x):
        s += "S"

    if not s:
        s = "EMPTY"
    print(s)
