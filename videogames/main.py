has={"alice": {"fishing"}, "bob": {"golf"}, "charlie": {"hockey"}}
for _ in range(int(input())):
    ws=input().split()
    n,g=ws[0],ws[-1]
    if g in has[n]:
        print(f"{n} already has {g}")
    else:
        n2 = n
        for n3 in has:
            if g in has[n3]:
                n2 = n3
                break
        print(f"{n} borrows {g} from {n2}")
        has[n2].remove(g)
        has[n].add(g)
