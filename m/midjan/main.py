input()
a=list(map(int,input().split()))
b=list(map(int,input().split()))
for x in a:
    if x not in b:
        print(x, end=" ")
print()
for x in b:
    if x not in a:
        print(x, end=" ")
print()
