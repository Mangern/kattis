a = 0
b = 0
for _ in range(3):
    x,y = map(int,input().split())
    a ^= x
    b ^= y

print(a,b,sep=" ")
