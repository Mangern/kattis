a = list(map(int,input().split()))
a.reverse()
n = a.pop()

C = [0 for _ in range(n+1)]

C[0] = a[0]

binom = [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1],
    [1,5,10,10,5,1],
    [1,6,15,20,15,6,1]
]

def value(x):
    ret = 0
    mul = 1
    for i in range(n+1):
        ret += mul * a[i]
        mul *= x
    return ret

for i in range(1,n+1):
    C[i] = value(i) - value(i-1)

    for j in range(1,i):
        C[i] -= binom[i-1][j-1] * C[j]

#C[1] = value(1) - value(0)
#
#print(list(map(value,range(n+1))))
#
#C[2] = value(2) - value(1) - C[1]

print(" ".join(map(str,C)))
