a=1
b=2
c=3
n=int(input())
print(1)
if n == 1:
    exit()
print(2)
for _ in range(n-2):
    print(c)
    s=a+b+c
    a=b
    b=c
    c=s
