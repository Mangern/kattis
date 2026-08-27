def possibilities(p):
    yield p
    for i in range(10):
        yield f"{i}{p}"
        yield f"{p}{i}"

    revc = ""
    for c in p:
        if ord('a') <= ord(c) <= ord('z'):
            revc += c.upper()
        elif ord('A') <= ord(c) <= ord('Z'):
            revc += c.lower()
        else:
            revc += c
    yield revc


s = input()
p = input()

print("Yes" if any(x == s for x in possibilities(p)) else "No")
