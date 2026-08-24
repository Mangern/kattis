a=[]
b=[]
while True:
    x=input()
    if x == "q":
        break
    a.append(x)
    b.append(tuple(x.split()))
print(a)
print(b)
