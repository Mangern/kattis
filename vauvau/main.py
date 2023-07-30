a,b,c,d = map(int,input().split())

def calc(x):
    def chk(y,h):
        k = (x%(y+h))
        if k == 0 or k > y:
            return 0
        return 1
    ans = (chk(a,b)+chk(c,d))

    print("one" if ans == 1 else ("none" if ans == 0 else "both"))

list(map(lambda x: calc(x),map(int,input().split())))
