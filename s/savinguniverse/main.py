for _ in range(int(input())):
    n = int(input())
    idx = dict()
    for i in range(n):
        idx[input()] = i

    q = int(input())
    a = [idx[input()] for i in range(q)]
    s = set()
    ans = 0

    for x in a:
        s.add(x)
        if len(s) == n:
            ans += 1
            s = {x}

    print(f"Case #{_+1}: {ans}")
