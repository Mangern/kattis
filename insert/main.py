nck = [[0]*101 for _ in range(101)]

for i in range(101):
    for j in range(i+1):
        # nck[i][j]
        if i == 0 or j == 0:
            nck[i][j] = 1
        else:
            nck[i][j] = nck[i-1][j-1] + nck[i-1][j]

def solve(a):
    if len(a) <= 1:
        return 1
    small = [x for x in a[1:] if x < a[0]]
    large = [x for x in a[1:] if x >= a[0]]
    return nck[len(small)+len(large)][len(small)] * solve(small) * solve(large)
while True:
    n=int(input())
    if not n:
        break
    a=list(map(int,input().split()))

    print(solve(a))

