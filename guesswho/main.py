n, m, q = map(int, input().split())
ppl = [(input(), _+1) for _ in range(n)]

for _ in range(q):
    i, c = input().split()
    i = int(i) - 1

    ppl = [(s, j) for s, j in ppl if s[i] == c]

if len(ppl) == 1:
    print(f"unique\n{ppl[0][1]}")
else:
    print(f"ambiguous\n{len(ppl)}")

