a,b,c=map(int,input().split())
ans=10**10
for op1 in "+-*/":
    for op2 in "+-*/":
        v=a
        if op1 == "/" and a % b != 0:
            continue
        if op1 == '+':
            v += b
        elif op1 == '-':
            v -= b
        elif op1 == '*':
            v *= b
        else:
            v //= b

        if op2 == '/' and v % c != 0:
            continue
        if op2 == '+':
            v += c
        elif op2 == '-':
            v -= c
        elif op2 == '*':
            v *= c
        else:
            v //= c
        if v<0:
            continue
        ans=min(ans,v)
print(ans)
