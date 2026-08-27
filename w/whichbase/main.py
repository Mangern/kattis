for _ in range(int(input())):
    tc,x=input().split()
    print(tc,end="")
    for b in [8,10,16]:
        print(" ",end="")
        try:
            print(int(x,b), end="")
        except:
            print(0, end="")
    print()
