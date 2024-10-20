def rats(s):
    res = str(int(s) + int(s[::-1]))
    return str(int("".join(sorted(res))))

def is_creeper(s: str):
    if s.startswith("1233") and s.endswith("4444"):
        if (set(s[4:-4]) | {'3'}) == {'3'}:
            return True
    elif s.startswith("5566") and s.endswith("7777"):
        if (set(s[4:-4]) | {'6'}) == {'6'}:
            return True
    return False

for _ in range(int(input())):
    t, m, s = input().split()
    m = int(m)

    vis = set()
    for i in range(m):
        if int(s) in vis:
            print(t, 'R', i+1)
            break
        if is_creeper(s):
            print(t, 'C', i+1)
            break
        vis.add(int(s))
        if i < m - 1:
            s = rats(s)
    else:
        print(t, s)
