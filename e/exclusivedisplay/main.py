letters = [
"""
.##.
#..#
#..#
....
#..#
#..#
.##.
""",
"""
....
...#
...#
....
...#
...#
....
""",
"""
.##.
...#
...#
.##.
#...
#...
.##.
""",
"""
.##.
...#
...#
.##.
...#
...#
.##.
""",
"""
....
#..#
#..#
.##.
...#
...#
....
""",
"""
.##.
#...
#...
.##.
...#
...#
.##.
""",
"""
.##.
#...
#...
.##.
#..#
#..#
.##.
""",
"""
.##.
...#
...#
....
...#
...#
....
""",
"""
.##.
#..#
#..#
.##.
#..#
#..#
.##.
""",
"""
.##.
#..#
#..#
.##.
...#
...#
.##.
""",
]

def to_int(s):
    s = s.replace(" ", "")
    s = s.replace("\n", "")
    s = s.replace("\r", "")
    s = s.replace(".", "0")
    s = s.replace("#", "1")
    i = int(s, 2)
    return i

s = ""
for i in range(7):
    s += input() + "\n"
i = to_int(s)

impossible = True
for j in range(100):
    a = str(j)
    res = to_int(letters[int(a[0])])
    if len(a) == 2:
        res ^= to_int(letters[int(a[1])])
    if res == i:
        impossible = False
        print(j, end=" ")
if impossible:
    print("impossible")
else:
    print()


