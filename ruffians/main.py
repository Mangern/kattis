for _ in range(int(input())):
    r1=list(map(int,input().split()))
    r2=list(map(int,input().split()))
    fail=True
    for i in range(len(r1)):
        for j in range(len(r2)):
            if i == j:
                continue
            if r1[i] == r2[j]:
                fail = False
    print("NO" if fail else "YES")
