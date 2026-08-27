for _ in range(int(input())):
    s = input()
    if s.startswith("simon says"):
        print(s[len("simon says "):])
    else:
        print()
