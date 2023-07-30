ascii = {
    '0': """
xxxxx
x...x
x...x
x...x
x...x
x...x
xxxxx""",
    '1': """
....x
....x
....x
....x
....x
....x
....x""",
    '2': """
xxxxx
....x
....x
xxxxx
x....
x....
xxxxx""",
    '3': """
xxxxx
....x
....x
xxxxx
....x
....x
xxxxx""",
    '4': """
x...x
x...x
x...x
xxxxx
....x
....x
....x""",
    '5': """
xxxxx
x....
x....
xxxxx
....x
....x
xxxxx""",
    '6': """
xxxxx
x....
x....
xxxxx
x...x
x...x
xxxxx""",
    '7': """
xxxxx
....x
....x
....x
....x
....x
....x""",
    '8': """
xxxxx
x...x
x...x
xxxxx
x...x
x...x
xxxxx""",
    '9': """
xxxxx
x...x
x...x
xxxxx
....x
....x
xxxxx""",
    '+': """
.....
..x..
..x..
xxxxx
..x..
..x..
....."""
}

def from_ascii(lines):
    s = "\n".join(lines)
    for c in ascii:
        if ascii[c].strip() == s:
            return c

inp = [input() for i in range(7)]

toks = []
for i in range(0, len(inp[0]), 6):
    curr = [l[i:i+5] for l in inp]
    toks.append(from_ascii(curr))

res = str(eval("".join(toks)))
out = [[] for i in range(7)]

for c in res:
    ls = ascii[c].split()
    for o,l in zip(out,ls):
        o.append(l)
print("\n".join(".".join(o) for o in out))

