def matmul(a, b):
    n = len(a)
    m = len(a[0])
    k = len(b[0])
    assert m == len(b)
    
    c = [[0] * k for _ in range(n)]
    
    for i in range(n):
        for j in range(k):
            for z in range(m):
                c[i][j] += a[i][z] * b[z][j]
    return c

def matpow(mat, p):
    if p == 0:
        result = [[0] * len(mat) for _ in range(len(mat))]
        for i in range(len(mat)):
            result[i][i] = 1
        return result
    
    ret = matpow(mat, p >> 1)
    ret = matmul(ret, ret)
    if p & 1:
        ret = matmul(ret, mat)
    return ret

n, m, s, t = map(int, input().split())

adj = [[0] * n for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u][v] = adj[v][u] = 1

res = matpow(adj, t)

print(sum(res[s]))
