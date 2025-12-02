def isp(x):
    if x <= 1:
        return False
    for i in range(2,x):
        if x % i == 0:
            return False
    return True
ans=[]
i = 1

while len(ans) < 100:
    while not isp(i):
        i += 1
    ans.append(i)
    i += 1
print("\n".join(map(str,ans)))
