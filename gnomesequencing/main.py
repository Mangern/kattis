print("Gnomes:")
for _ in range(int(input())):
    a = list(map(int,input().split()))
    if sorted(a) == a or sorted(a, reverse=True) == a:
        print("Ordered")
    else:
        print("Unordered")
