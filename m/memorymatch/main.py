def main():
    n = int(input())
    k = int(input())

    name = ["" for i in range(n)]

    bad = [False for i in range(n)]

    for _ in range(k):
        c1, c2, p1, p2 = input().split()
        c1, c2 = [int(x)-1 for x in (c1, c2)]

        name[c1] = p1
        name[c2] = p2

        if p1 == p2:
            bad[c1] = True
            bad[c2] = True

    ans = 0

    counts = {}

    nempty = 0

    for i in range(n):
        if bad[i]:
            continue
        if name[i] == "":
            nempty += 1
        else:
            counts[name[i]] = counts.get(name[i], 0) + 1

    cone = 0
    for k, v in counts.items():
        if v == 2:
            ans += 1
        else:
            assert v == 1
            cone += 1

    if cone == nempty:
        ans += cone
    else:
        if nempty == 2:
            ans += 1

    print(ans)



main()
