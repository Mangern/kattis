from itertools import product

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def variation(t):
    poss_fst = [t[0]] if t[0] != '*' else list(map(str,range(1,7)))
    poss_scd = [t[1]] if t[1] != '*' else list(map(str,range(1,7)))
    return product(poss_fst, poss_scd)

def beats(a,b):
    s_a = (max(*a),min(*a))
    s_b = (max(*b),min(*b))

    if s_b == ('2','1'):
        return False
    elif s_a == ('2','1'):
        return True
    
    if s_b[0] == s_b[1]:
        if s_a[0] != s_a[1]:
            return False
        return s_a[0] > s_b[0]
    elif s_a[0] == s_a[1]:
        return True

    i_a = int(s_a[0]+s_a[1])
    i_b = int(s_b[0]+s_b[1])

    return i_a > i_b

def solve(p1, p2):
    win = 0
    poss = 0
    for s in variation(p1):
        for t in variation(p2):
            if beats(s,t):
                win += 1
            poss += 1
    g = gcd(win,poss)
    win //= g
    poss //= g
    if win == 0:
        print(0)
    elif win == poss:
        print(1)
    else:
        print(f"{win}/{poss}")

while True:
    s = input().split()
    if '0' in s:
        break
    solve(tuple(s[:2]), tuple(s[2:]))

