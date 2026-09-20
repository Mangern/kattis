def ftoi(s):
    while len(s) < 5:
        s += '0'
    return int(s)
s1=input()
s2=input()

l1 = s1.split(".")
l2 = s2.split(".")

t1 = tuple(map(int,l1))
t2 = tuple(map(int,l2))

x1 = t1[0] * 10**5 + ftoi(l1[1])
x2 = t2[0] * 10**5 + ftoi(l2[1])

if x1 > x2 and t1 > t2:
    print(s1)
elif x2 > x1 and t2 > t1:
    print(s2)
else:
    print(-1)
