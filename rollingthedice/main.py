s=input()
x, rest = s.split('d')
x = int(x)
y, z = map(int, rest.split('+'))
a1=x*1+z
a2=x*y+z
print((a1+a2)/2)
