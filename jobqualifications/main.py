from sys import stdin
def main():
    lines=stdin.read().splitlines()
    ptr = 0
    def input():
        nonlocal ptr
        nonlocal lines
        ret=lines[ptr]
        ptr += 1
        return ret

    n,m=map(int, input().split())
    s=set(input() for _ in range(n))
    for _ in range(m):
        k=int(input())
        ok=True
        for i in range(k):
            t=input()
            if ok:
                if t not in s:
                    ok=False
        print("apply" if ok else "why bother?")
main()
