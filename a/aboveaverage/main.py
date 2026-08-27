for _ in range(int(input())):
    a=list(map(int,input().split()))[1:]
    sm=sum(a)
    n=len(a)
    cnt=sum(1 for x in a if x*n > sm)
    perc=cnt/n * 100
    print(f"{perc:.3f}%")
