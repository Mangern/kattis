a,b=map(int,input().split())
if b<a:
    a,b=b,a

for c in range(1,a+b):
    if c <= b:
        if b**2 == a**2+c**2:
            print(c)
            exit()
    else:
        if c**2 == a**2+b**2:
            print(c)
            exit()
print("Pythagoras is sad :(")
