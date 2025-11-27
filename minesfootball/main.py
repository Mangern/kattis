a1=-10**10
a2=10**10
a3=a1
a4=a2

for _ in range(int(input())):
    a=list(map(int,input().split()))[1:]
    a1 = max(a1,max(a))
    a2 = min(a2,min(a))
    a3 = max(a3,sum(a))
    a4 = min(a4,sum(a))
print(a1)
print(a2)
print(a3)
print(a4)
