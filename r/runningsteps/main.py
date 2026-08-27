nck=[[0]*101 for _ in range(101)]
for i in range(101):
    for j in range(i+1):
        if i == 0 or j == 0:
            nck[i][j] = 1
        else:
            nck[i][j] = nck[i-1][j-1] + nck[i-1][j]

for _ in range(int(input())):
    k,s = map(int, input().split())

    ans=0
    for n2 in range(s):
        if n2 * 2 > s:
            break
        n1 = s - 2 * n2
        if n1 > n2:
            continue
        if n1 % 2 == 1 or n2 % 2 == 1:
            continue

        ntot=n1+n2
        # ntot//2 choose n1//2
        ans += nck[ntot//2][n1//2]**2
    print(k, ans)
