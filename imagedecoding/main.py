hs = False
while True:
    lens = set()
    n = int(input())
    if not n:
        break
    if hs:
        print()
    hs = True
    for _ in range(n):
        a = input().split()
        o = ".#".index(a[0])
        ut = "".join(".#"[(o+i)%2]*int(x) for i, x in enumerate(a[1:]))
        print(ut)
        lens.add(len(ut))
    if len(lens)>1:
        print("Error decoding image")
