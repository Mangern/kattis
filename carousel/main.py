while True:
    n, m = map(int, input().split())
    if not m+n:
        break
    
    ans = None
    for i in range(n):
        a, b = map(int, input().split())
        if a > m:
            continue
        if ans is None or b * ans[0] < a*ans[1] or (b*ans[0] == a*ans[1] and a > ans[0]):
            ans = (a, b)

    print(f"Buy {ans[0]} tickets for ${ans[1]}" if ans else "No suitable tickets offered")
