for _ in range(int(input())):
    a, b, c, d = input().split()
    a = ord(a) - ord('A')
    b = int(b) - 1
    c = ord(c) - ord('A')
    d = int(d) - 1

    if (a + b) % 2 != (c + d) % 2:
        print("Impossible")
        continue

    valid = [(i, j) for i in range(8) for j in range(8) if (i+j)%2 == (a+b)%2]

    def cpos(p):
        return f"{chr(ord('A') + p[0])} {p[1]+1}"

    if (a,b) == (c, d):
        print(0, cpos((a,b)))
        continue

    def reach(p1, p2):
        p1a, p1b = p1
        p2a, p2b = p2

        return p1a + p1b == p2a + p2b or p1a - p1b == p2a - p2b

    if reach((a,b), (c,d)):
        print(1, cpos((a,b)), cpos((c,d)))
        continue

    for i in range(len(valid)):
        if valid[i] == (a,b):
            continue
        if valid[i] == (c,d):
            continue

        if reach((a,b), valid[i]) and reach(valid[i], (c,d)):
            print(2, cpos((a,b)), cpos(valid[i]), cpos((c,d)))
            break
