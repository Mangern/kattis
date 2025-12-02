vow = "aeiou"
while True:
    s = input()
    if s == "end":
        break

    n = len(s)

    valid=True
    for i in range(n):
        if i + 2 < n:
            if s[i] in vow and s[i+1] in vow and s[i+2] in vow:
                valid = False
            if s[i] not in vow and s[i+1] not in vow and s[i+2] not in vow:
                valid = False
        if i + 1 < n:
            if s[i] == s[i+1] and s[i] not in "oe":
                valid = False
    if all(c not in vow for c in s):
        valid = False
    print(f"<{s}> is{' not ' if not valid else ' '}acceptable.")
