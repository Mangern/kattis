from itertools import chain
chlist = ["BFPV","CGJKQSXZ","DT","L","MN","R"]


def get_code(c):
    for i, s in enumerate(chlist):
        if c in s:
            return i+1
    return 0

while True:
    try:
        s = input()
        a = list(map(get_code, s))
        b = [y for x, y in zip(chain([0], a), a) if x != y]
        print("".join(map(str, filter(lambda x: x, b))))
    except:
        break

