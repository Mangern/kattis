from fractions import Fraction
for _ in range(int(input())):
    a,b,op,c,d=input().split()
    f1=Fraction(int(a),int(b))
    f2=Fraction(int(c),int(d))
    if op == '+':
        ans=f1+f2
    elif op == '-':
        ans=f1-f2
    elif op == '*':
        ans=f1*f2
    else:
        ans=f1/f2
    print(ans.numerator, '/', ans.denominator)
