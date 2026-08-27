BIG = (1<<(32*4))
magic_inv = 0x3cc9d934ebd7e2c25703a69a67e1a395

n = int(input())

for i in range(n):
    s = input()
    x = int(s, 16)
    x = (x * magic_inv) % BIG

    r = []
    while x:
        c = chr(x&((1<<7)-1))
        r.append(c)
        x >>= 7

    r.pop()
    ans = "".join(r)

    print(f"{s}:{ans}")
