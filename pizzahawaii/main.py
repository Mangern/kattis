from pprint import pprint
for _ in range(int(input())):
    n = int(input())
    f_set = dict()
    n_set = dict()
    for i in range(n):
        pizza = input()
        fore = input().split()[1:]
        for w in fore:
            if w not in f_set:
                f_set[w] = set()
            f_set[w].add(pizza)

        nati = input().split()[1:]
        for w in nati:
            if w not in n_set:
                n_set[w] = set()
            n_set[w].add(pizza)

    ans_pairs = []
    for v in f_set:
        for w in n_set:
            if f_set[v] == n_set[w]:
                ans_pairs.append((v,w))
    ans_pairs.sort()
    print("\n".join(map(lambda t: f"({t[0]}, {t[1]})",ans_pairs)))
    print()
