def main():
    memo = {}
    def solve(lo,hi,k):
        if (lo,hi,k) in memo:
            return memo[(lo,hi,k)]
        if k == 1:
            return (hi*(hi+1))//2-(lo*(lo-1))//2
        if lo > hi:
            return 0
        if lo == hi:
            return lo

        r = None
        for i in range(lo,hi+1):
            check = max(i+solve(lo,i-1,k-1), i+solve(i+1,hi,k))
            if r is None or check < r:
                r = check
        memo[(lo,hi,k)] = r
        return r

    for _ in range(int(input())):
        k,m=map(int,input().split())
        print(solve(1,m,k))
main()
