n=int(input())
if n == 1:
    print(0)
    exit()
fac=[1]
for i in range(1,10):
    fac.append(fac[-1]*i)
ptr = 9
ans=[]
while n > 0:
    while fac[ptr] > n:
        ptr -= 1
    n -= fac[ptr]
    ans.append(ptr)
print("".join(map(str,ans[::-1])))
