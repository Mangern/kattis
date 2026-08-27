n=int(input())
closest=None
for place in range(18,-1,-1):
    for dig in range(9,0,-1):
        val=int(f"{dig}"+"0"*place)
        if closest is None or abs(val-n) < abs(closest-n):
            closest=val
print(closest)
