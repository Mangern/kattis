for _ in range(int(input())):
    a = input().split()
    rem = set()
    while True:
        words = input().split()
        if words[-1][-1] == '?':
            break
        rem.add(words[-1])
    print(" ".join(x for x in a if x not in rem))
