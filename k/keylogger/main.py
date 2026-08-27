keys = {
    "clank": "A",
    "bong": "B",
    "click": "C",
    "tap": "D",
    "poing": "E",
    "clonk": "F",
    "clack": "G",
    "ping": "H",
    "tip": "I",
    "cloing": "J",
    "tic": "K",
    "cling": "L",
    "bing": "M",
    "pong": "N",
    "clang": "O",
    "pang": "P",
    "clong": "Q",
    "tac": "R",
    "boing": "S",
    "boink": "T",
    "cloink": "U",
    "rattle": "V",
    "clock": "W",
    "toc": "X",
    "clink": "Y",
    "tuc": "Z",
    "whack": " ",
}

caps = False
shift = False

n = int(input())

ans = ""
for i in range(n):
    w = input()

    if w == "bump":
        caps = not caps
    elif w == "dink":
        caps = not caps
    elif w == "thumb":
        caps = not caps
    elif w == "pop":
        ans = ans[:-1]
    else:
        ch = keys[w]
        if not caps:
            ch = ch.lower()
        ans += ch
print(ans)
