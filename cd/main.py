import sys

def get_int(): return int(sys.stdin.readline())
def get_ints(): return map(int, sys.stdin.readline().strip().split())


while True:
    n,m = get_ints()
    if n == 0 and m == 0:
        break
    ha = set()
    ans = 0

    for i in range(n):
        a = get_int()
        ha.add(a)

    for i in range(m):
        b = get_int()
        if b in ha:
            ans += 1
    print(ans)
