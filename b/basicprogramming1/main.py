n, t = map(int, input().split())
A = list(map(int, input().split()))

if t == 1:
    print(7)
elif t == 2:
    print("Bigger" if A[0] > A[1] else ("Equal" if A[0] == A[1] else "Smaller"))
elif t == 3:
    print(sorted(A[:3])[1])
elif t == 4:
    print(sum(A))
elif t == 5:
    print(sum((x for x in A if not (x&1))))
elif t == 6:
    print("".join(chr(ord('a')+x%26) for x in A))
elif t == 7:
    i = 0
    reached: set[int] = set()
    while True:
        i = A[i]
        if i in reached:
            print("Cyclic")
            break
        reached.add(i)
        if i < 0 or i >= n:
            print("Out")
            break
        if i == n - 1:
            print("Done")
            break
