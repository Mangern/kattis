ws = input().strip().split(" + ")
per = ["H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"]
may = [chr(0x1d2e0+i) for i in range(20)]
def exgcd(a, b):
    if a == 0:
        return b, 0, 1
    g, x1, y1 = exgcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return g, x, y

def to_may(x):
    pw = 1
    while pw * 20 <= x:
        pw *= 20
    ret=[]
    while pw > 0:
        num = x // pw
        ret.append(may[num])
        x -= num * pw
        pw //= 20
    return "".join(ret)

def from_may(m):
    ret = 0
    for c in m:
        dig = may.index(c)
        ret *= 20
        ret += dig
    return ret

if len(ws) == 2:
    a, b = ws
    if a.isdigit() and b.isdigit():
        print(int(a)+int(b))
        exit()
    if a.startswith('"') and a.endswith('"') and b.startswith('"') and b.endswith('"'):
        print(a[1:-1]+b[1:-1])
        exit()
    try:
        res = int(a,16)+int(b,16)
        print(f"0x{res:x}")
        exit()
    except Exception as e:
        pass

    if a.startswith("log(") and a.endswith(")") and b.startswith("log(") and b.endswith(")"):
        x = int(a[4:-1]) * int(b[4:-1])
        print(f"log({x})")
        exit()

    if a.startswith("{") and a.endswith("}") and b.startswith("{") and b.endswith("}"):
        lst = sorted(eval(a)|eval(b))
        ans = ", ".join(map(str, lst))
        print(f"{{{ans}}}")
        exit()

    if a in per and b in per:
        ia = per.index(a) + 1
        ib = per.index(b) + 1
        print(per[ia+ib-1])
        exit()

    if all(c in may for c in a) and all(c in may for c in b):
        ia = from_may(a)
        ib = from_may(b)
        print(to_may(ia + ib))
        exit()

    if " mod " in a and " mod " in b:
        na, da = map(int, a.split(" mod "))
        nb, db = map(int, b.split(" mod "))
        g, x1, y1 = exgcd(da, db)
        ans = na * y1 * db + nb * x1 * da
        ans = ans % (da * db)
        print(f"{ans} mod {da * db}")
        exit()

    if a == "tragedy" and b == "time":
        print("comedy")
        exit()
    if a == "repetition" and b == "repetition":
        print("learning")
        exit()
    if a == "fire" and b == "water":
        print("steam")
        exit()
    if a == "red" and b == "blue":
        print("purple")
        exit()
    if a == "icelander" and b == "deadline":
        print("procrastination")
        exit()
    if a == "throat" and b == "potato":
        print("danish")
        exit()
    if a == "kattis" and b == "program":
        print("verdict")
        exit()
    if a == "problem" and b == "solution":
        print("AC")
        exit()
    if a == "contest" and b == "geometry":
        print("WA")
        exit()
    if a == "nonsense" and b == "annoyance":
        print("this problem")
        exit()

    print("purple")
    exit()
if len(ws) == 4:
    a,b,c,d = ws
    if a.isdigit() and c.isdigit() and b.endswith("i") and b[:-1].isdigit() and d.endswith("i") and d[:-1].isdigit():
        ra = int(a)
        ia = int(b[:-1])
        rb = int(c)
        ib = int(d[:-1])
        print(f"{ra+rb} + {ia + ib}i")
        exit()

    print(ws)
    assert False

print(ws)
