for _ in range(int(input())):
    ws=input().split()
    m=int(ws[0])
    o=int(ws[1])
    if ws[2] == '+':
        # Make O in profit betting 100?
        prof=o*m/100
        print(prof)
    else:
        # Make 100 in profit betting O?
        prof=100*m/o
        print(prof)
