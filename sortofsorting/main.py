while True:
    n = int(input())
    if not n:
        break
    s = [input() for i in range(n)]
    s.sort(key=lambda a:a[:2])
    print("\n".join(s))
    print()
