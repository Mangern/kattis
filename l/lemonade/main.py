def main():
    n, m = map(int, input().split())
    a,b,c,d,e,f,v0 = map(int, input().split())

    states = set([(0, 0, v0)]) # cap[N], score, v, l

    max_score = 0
    for i in range(1, m+1):
        nstates = set()
        for capn, score, v in states:
            l = (d * i + e * v) % f
            v = (a * i + b * v) % c + 1
            # Two choices
            if capn + v <= n:
                max_score = max(max_score, score + l)
                if capn + v < n:
                    nstates.add((capn+v, score + l, 0))

            if score + (f-1) * (m + 1 - i) > max_score:
                nstates.add((capn, score, v))

        states = nstates

    print(max_score)

main()
