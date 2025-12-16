res=1
for _ in range(int(input())):
    a,op,b=input().split()
    a,b=map(int,(a,b))
    if op == '+':
        res = a+b - res
    if op == '-':
        res *= a-b
    if op == '*':
        res=a*a*b*b
    if op == '/':
        res=(a+1)//2
    print(res)
