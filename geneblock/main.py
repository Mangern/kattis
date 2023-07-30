for _ in range(int(input())):
    n = int(input())
    ans = 0
    while n > 7 and n % 10 != 7:
        n -= 7
        ans += 1
    if n % 10 == 7:
        print(ans+1)
    else:
        print(-1)
