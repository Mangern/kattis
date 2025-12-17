n=int(input())
x=1
while True:
    if (n+x*60)//3600 > n//3600:
        break
    x += 1
print(x)
