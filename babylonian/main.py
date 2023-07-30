for _ in range(int(input())):
    a = [x.strip() for x in input().split(",")]
    a = [int(x) if len(x) else 0 for x in a]

    mul = 1
    ans = 0
    for x in a[::-1]:
        ans += x * mul
        mul *= 60
    print(ans)
