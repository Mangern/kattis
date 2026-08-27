
ones = [
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
]

tens = [
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC",
]

def get(x):
    t = x // 10
    o = x % 10
    return tens[t] + ones[o]

s = list(input())
s.sort()
s = "".join(s)

for i in range(1, 101):
    rom = get(i)
    if "".join(sorted(list(rom))) == s:
        print(rom)
        break
