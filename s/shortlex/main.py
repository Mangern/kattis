for _ in range(int(input())):
    n=int(input())-1
    l=1
    num=0
    while True:
        if num+2**l>=n:
            break
        num+=2**l
        l+=1
    n-=num
    ans=[]
    isf=n==2**l
    for i in range(l):
        ans.append(n&1)
        n>>=1
    print(("0" if isf else "")+"".join(map(str,ans[::-1])))
