def main():
    n = int(input())
    pts = [tuple(map(int,input().split())) for _ in range(n)]


    def check(a):
        sm = 0
        for x,y in pts:
            t = (x+y-a)/2
            sm += (x-t)*(x-t)+(y-t-a)*(y-t-a)
        return sm

    a = [y-x for x,y in pts]

    print(sum(a)/n)


main()
