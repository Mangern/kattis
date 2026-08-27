MOD = 10**9
def matmul(A, B):
    ret =  ((A[0][0] * B[0][0] + A[0][1] * B[1][0],
             A[0][0] * B[0][1] + A[0][1] * B[1][1],),
            (
             A[1][0] * B[0][0] + A[1][1] * B[1][0],
             A[1][0] * B[0][1] + A[1][1] * B[1][1]))
    return ((ret[0][0] % MOD, ret[0][1] % MOD), (ret[1][0] % MOD, ret[1][1] % MOD))

def matpow(A, n):
    if n == 1:
        return A
    r = matpow(A, n >> 1)
    r = matmul(r, r)
    if n & 1:
        r = matmul(r, A)
    return r

for _ in range(int(input())):
    k, n = map(int, input().split())
    print(k, end=" ")
    A = matpow(((1, 1), (1, 0)), n)
    print(A[0][1])
