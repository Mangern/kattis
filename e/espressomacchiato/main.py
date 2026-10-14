for _ in range(int(input())):
    n=int(input())
    a=[["."]*n for _ in range(n)]
    a[n-2][n-1] = "C"
    a[n-1][n-2] = "C"
    print("\n".join("".join(s) for s in a))
