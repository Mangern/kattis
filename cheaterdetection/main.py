for _ in range(int(input())):
    s=input().replace('.','')
    x=int(s)
    k = (x*10 + 14) // 15
    print("VALID" if k * 15 // 10 == x else "IMPOSSIBLE")
