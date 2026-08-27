a=int(input())
b=int(input())
dif=(a-b)%360
print(min(dif,360-dif))
