from collections import Counter as freq
lens = {
    ".":       1,
    "..":      3,
    "-":       3,
    "...":     5,
    "-.":      5,
    ".-":      5,
    "....":    7,
    "-..":     7,
    ".-.":     7,
    "..-":     7,
    "--":      7,
    ".....":   9,
    "-...":    9,
    ".-..":    9,
    "..-.":    9,
    "...-":    9,
    "--.":     9,
    "-.-":     9,
    ".--":     9,
    "......": 11,
    "-....":  11,
    ".-...":  11,
    "..-..":  11,
    "...-.":  11,
    "....-":  11,
    "--..":   11
}

poss = [x for x in lens]
poss.sort(key=lambda x: lens[x])

s = input()
s = "".join(c.upper() for c in s if ord('A') <= ord(c.upper()) <= ord('Z'))
ans = 0
for i, (_,cnt) in enumerate(freq(s).most_common()):
    ans += cnt * lens[poss[i]]

ans += (len(s) - 1) * 3
print(ans)
    
