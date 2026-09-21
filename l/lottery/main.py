M,N,T,P=map(int,input().split())

nck = [[0]*1001 for _ in range(1001)]

nck[0][0] = 1
for n in range(1, 1001):
    nck[n][0] = 1
    for k in range(1,n+1):
        nck[n][k] = nck[n-1][k-1]+nck[n-1][k]


ans = 0.0
for k in range(1, P+1):
    if T * k >= P and k <= N and (P - k) <= M - N:
        prob = nck[N][k] * nck[M-N][P-k] / nck[M][P]
        ans += prob
print(ans)
