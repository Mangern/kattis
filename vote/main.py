for _ in range(int(input())):
    n = int(input())
    v = [(int(input()),i+1) for i in range(n)]
    v.sort()

    sm = sum(x[0] for x in v)
    if v[-1][0] == v[-2][0]:
        print("no winner")
    else:
        if 2*v[-1][0] > sm:
            print(f"majority winner {v[-1][1]}")
        else:
            print(f"minority winner {v[-1][1]}")
             
