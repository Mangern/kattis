def mini(x):
    if x == 0:
        return []

    a = 0
    b = 1
    while b <= x:
        a,b = b,a+b
    res = mini(x-a)
    res.append(a)
    return res

print(" ".join(map(str,mini(int(input())))))
