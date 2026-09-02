def fmt(x):
    if x < 0:
        return f"({x})"
    return f"{x}"
a,b,c,d=map(int,input().split())
x1=a*c+b*d
y1=a*d-b*c
x2=a*c-b*d
y2=a*d+b*c

result=x1**2+y1**2

if x1 == x2 and y1 == y2:
    print(f"{fmt(x1)}^2 + {fmt(y1)}^2 = {result}")
    print(f"{fmt(-x1)}^2 + {fmt(-y1)}^2 = {result}")
else:
    print(f"{fmt(x1)}^2 + {fmt(y1)}^2 = {result}")
    print(f"{fmt(x2)}^2 + {fmt(y2)}^2 = {result}")
