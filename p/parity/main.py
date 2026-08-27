while True:
    s=list(input())
    if "#" in s:
        break
    s=[c for c in s if c in "01eo"]
    n1=sum(1 for c in s if c =='1')
    s[-1]= '1' if ((n1&1) and s[-1]=='e') or ((not (n1&1)) and s[-1]=='o') else '0'
    print("".join(s))
