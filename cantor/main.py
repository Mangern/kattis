from math import gcd
def cantor(num, den, depth=0):
    g=gcd(num,den)
    num //= g
    den //= g
    # num / den < 1 / 3
    if depth>=100:
        return True

    if num == 0:
        return True

    if num * 3 < den:
        return cantor(3*num, den, depth + 1)
    elif num * 3 >= 2 * den:
        return cantor(3*num - 2 * den, 3 * den, depth+1)
    return False

while True:
    s=input()
    if s == "END":
        break
    if s == "1" or s == "0":
        print("MEMBER")
        continue

    dotidx=s.find(".")
    num = int(s[dotidx+1:])
    den = 10**(len(s[dotidx+1:]))
    print("MEMBER" if cantor(num,den) else "NON-MEMBER")
