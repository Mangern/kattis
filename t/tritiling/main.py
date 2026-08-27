dp = {}

def f(a, b, c):
    if a == b == c == 0:
        return 1
    if min(a,b,c) < 0:
        return 0

    if (a, b, c) in dp:
        return dp[(a,b,c)]

    ans = 0

    if a > b:
        ans = f(a - 2, b, c)
    elif b > c and b > a:
        ans = f(a, b - 2, c)
    elif c > b:
        ans = f(a, b, c - 2)
    else:
        if a == b == c:
            ans = (
                f(a - 1, b - 1, c) +
                f(a, b - 1, c - 1) + 
                f(a - 2, b - 2, c - 2)
            )
        elif a == b:
            ans = (
                f(a - 1, b - 1, c) + 
                f(a - 2, b - 2, c)
            )
        elif b == c:
            ans = (
                f(a, b - 1, c - 1) +
                f(a, b - 2, c - 2)
            )
        else:
            assert False

    dp[(a,b,c)] = ans
    return ans

def main():
    while True:
        n = int(input())
        if n == -1:
            break
        print(f(n,n,n))

if __name__ == "__main__":
    main()
