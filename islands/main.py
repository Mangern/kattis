for _ in range(int(input())):
    print(_+1, end=" ")
    a = list(map(int, input().split()))[1:]

    ans = 0
    for i in range(1, len(a) - 1):
        for j in range(1, i + 1):
            if min(a[j:i+1]) > a[j - 1] and min(a[j:i+1]) > a[i+1]:
                ans += 1
    print(ans)
