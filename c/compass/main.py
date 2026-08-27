a=int(input())
b=int(input())

x = (b-a+360)%360
y = (a-b+360)%360

mn = x
if y < x:
    mn = -y

print(mn)
