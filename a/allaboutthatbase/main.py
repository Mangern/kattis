def conv(s, b):
    if b == 1:
        if set(s) != {"1"}:
            return -1
        return len(s)
    try:
        return int(s, b)
    except:
        return -1

for _ in range(int(input())):
    a, op, b, eq, r = input().split()
    ans = []
    for bs in range(1,37):
        x = conv(a, bs)
        y = conv(b, bs)
        z = conv(r, bs)
        if x == -1 or y == -1 or z == -1:
            continue

        
        good = False
        if op == "/":
            good = (x == y * z)
        else:
            good = (eval(f"{x} {op} {y}") == z)

        if good:
            ans.append("123456789abcdefghijklmnopqrstuvwxyz0"[bs-1])
    if not ans:
        print("invalid")
    else:
        print("".join(ans))
