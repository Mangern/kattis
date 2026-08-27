for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    fail = False
    for i in range(n):
        for j in range(i+1, n):
            b = a[i:j+1]
            cnts = dict()
            for x in b:
                if x not in cnts:
                    cnts[x] = 0
                cnts[x] += 1

            if 1 not in cnts.values():
                fail = True
                break

        if fail:
            break

    if not fail:
        print("non-boring")
    else:
        print("boring")
