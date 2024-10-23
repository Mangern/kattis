from sys import stdin

for i, line in enumerate(stdin):
    if i > 0:
        print()
    n = int(line)
    cnt = {}
    while True:
        s = input()
        if s == "EndOfText":
            break
        s = s.lower()
        for i in range(255):
            if i < ord('a') or i > ord('z'):
                s = s.replace(chr(i), " ")
        ws = s.split()
        for w in ws:
            cnt[w] = cnt.get(w, 0) + 1

    ans = []
    for w in cnt:
        if cnt[w] == n:
            ans.append(w)
    if ans:
        ans.sort()
        print("\n".join(ans))
    else:
        print("There is no such word.")

