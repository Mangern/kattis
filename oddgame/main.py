for _ in range(int(input())):
    nw=0
    n,m=map(int,  input().split())
    for _ in range(n):
        for c in input():
            if c == 'W':
                nw += 1
    print("Alice" if nw % 2 == 1 else "Bob")
