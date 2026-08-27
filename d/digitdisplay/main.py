n=int(input())
if n == 1:
    print("impossible")
    exit()

ans=[]
if n & 1:
    ans.append(7)
    n -= 3
n //= 2
for _ in range(n):
    ans.append(1)
print("".join(map(str,ans)))
