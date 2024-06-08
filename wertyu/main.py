from sys import stdin

rows = [
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;'",
    "ZXCVBNM,./"
]

for line in stdin:
    for c in line:
        if c == " ":
            print(c, end="")
        else:
            for row in rows:
                if c in row:
                    print(row[row.index(c)-1], end="")
    print()
