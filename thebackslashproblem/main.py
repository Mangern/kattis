def is_special(c):
    return ord('!') <= ord(c) <= ord('*') or ord('[') <= ord(c) <= ord(']')

def escapi(s):
    new_s = []
    for c in s:
        if is_special(c):
            new_s.append("\\")
        new_s.append(c)
    return new_s

while True:
    try:
        n = int(input())
        s = list(input())

        for _ in range(n):
            s = escapi(s)
        print("".join(s))
    except:
        break
