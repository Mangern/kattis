def main():
    ans = None
    def count(n, bad, used: int, prev = []):
        nonlocal ans
        if used == (1<<n)-1:
            if ans is None:
                ans = [i for i in prev]
            return 1
        cnt = 0

        for i in range(n):
            if used & (1<<i):
                continue
            if len(prev) and ((prev[-1], i) in bad or (i, prev[-1]) in bad):
                continue
            used += (1<<i)
            prev.append(i)
            cnt += count(n, bad, used, prev)
            used -= (1<<i)
            prev.pop()
        return cnt

    def solve():
        nonlocal ans
        ans = None
        n = int(input())
        cols = input().split()
        m = int(input())
        bad = {
            (lambda t: (cols.index(t[0]), cols.index(t[1])))(input().split())
            for _ in range(m)
        }
        print(count(n, bad, 0, []))
        print(" ".join(cols[i] for i in ans))


    for _ in range(int(input())):
        solve()

main()
