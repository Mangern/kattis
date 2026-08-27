k,s=map(int,input().split())
x=0
while s-k*(x+1)>=0:
    x += 1

print(x+s-k*x)
