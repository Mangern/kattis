a,b=map(int,input().split())

k = a//b

x = k * b
y = (k+1)*b

print(min(y-a,a-x))
