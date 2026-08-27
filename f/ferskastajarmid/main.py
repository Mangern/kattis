arr=[]
for _ in range(int(input())):
    a,b,c=input().split()
    arr.append((-int(b)*int(c),a))
print(min(arr)[1])
