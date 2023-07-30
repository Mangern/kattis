for _ in range(int(input())):
    s = input().strip()
    t = input().strip()
    print(s)
    print(t)
    print("".join(map(lambda t: "*" if t[0] != t[1] else ".", zip(s,t))))
    print()
