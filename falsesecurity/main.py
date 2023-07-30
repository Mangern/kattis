from sys import stdin

code = {
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    '_': '..--',
    ',': '.-.-',
    '.': '---.',
    '?': '----'
}

def dec(st):
    for i in code:
        if code[i] == st:
            return i
    assert False

for line in stdin:
    morse = "".join(code[x] for x in line.strip())
    lens = [len(code[x]) for x in line.strip()][::-1]

    i = 0
    ans = []
    for l in lens:
        ans.append(dec(morse[i:i+l]))
        i += l

    print("".join(ans))
