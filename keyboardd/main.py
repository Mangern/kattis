def string_chopper(s):
    cur = ""
    for c in s:
        if cur == "" or c == cur[0]:
            cur += c
        else:
            yield cur
            cur = c
    yield cur

s, t = input(), input()

sticky = set()
for a, b in zip(string_chopper(s), string_chopper(t)):
    if len(b) > len(a):
        sticky.add(a[0])

print("".join(sticky))
