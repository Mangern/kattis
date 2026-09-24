n=int(input())
ans=[1]
while 2*ans[-1] <= n:
    ans.append(2*ans[-1])
print(len(ans))
print(" ".join(map(str,ans)))
