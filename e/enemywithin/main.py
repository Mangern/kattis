n=int(input())
if n <= 2:
    ans=[1]*n
else:
    a=list(range(2,n))
    ans= a + a if (n&1) else a + a[::-1]
print(len(ans))
print("\n".join(map(str,ans)))
