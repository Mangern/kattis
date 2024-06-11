from itertools import takewhile
import time

def main():
    base = [
        (1000, "M"),
        (900, "CM"),
        (800, "DCCC"),
        (700, "DCC"),
        (600, "DC"),
        (500, "D"),
        (400, "CD"),
        (300, "CCC"),
        (200, "CC"),
        (100, "C"),
        (90, "XC"),
        (80, "LXXX"),
        (70, "LXX"),
        (60, "LX"),
        (50, "L"),
        (40, "XL"),
        (30, "XXX"),
        (20, "XX"),
        (10, "X"),
        (9, "IX"),
        (8, "VIII"),
        (7, "VII"),
        (6, "VI"),
        (5, "V"),
        (4, "IV"),
        (3, "III"),
        (2, "II"),
        (1, "I")
    ]

    def toroman(x):
        th = x // 1000
        ans = ["M" * th]
        x -= 1000 * th
        while x > 0:
            for val, s in base:
                if val <= x:
                    ans.append(s)
                    x -= val
                    break
        return "".join(ans)

    lst = [
        (toroman(i), i) for i in range(1, 1000)
    ]

    lst.sort()

    idx = {}
    nidx = [0] * 1000
    for i, (rom, num) in enumerate(lst):
        idx[rom] = i
        nidx[num] = i

    vidx = idx["V"]

    for _ in range(int(input())):
        n = int(input())
        r = toroman(n)
        if r[0] == "C":
            print(nidx[n]+1)
        elif r[0] == "D":
            print(nidx[n]+1)
        elif r[0] == "I":
            print(nidx[n]+1)
        elif r[0] == "L":
            print(nidx[n]+1)
        elif r[0] == "M":
            n_ms = len(list(takewhile(lambda c: c == "M", r)))
            rest = r[n_ms:]
            if not rest:
                print(n_ms * (vidx+1))
            elif rest[0] not in "XV":
                print(n_ms * (vidx+1) + idx[rest]+1)
            else:
                res = - n_ms * (1000 - vidx - 1) + idx[rest] - len(lst)
                print(res)

        elif r[0] in "XV":
            print(nidx[n] - len(lst))
            continue
        else:
            assert False
    #print("Roman:", roman_sum)
main()
