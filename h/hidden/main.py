s,t = input().split()

for c in t:
    if c in s:
        if s.index(c) != 0:
            print("FAIL")
            break
        s = s[1:]
else:
    print("FAIL" if s else "PASS")
