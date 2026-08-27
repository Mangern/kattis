n,m=map(int,input().split())
drink=[input() for _ in range(n)]
ptr={}
for _ in range(m):
    s=input()
    if s not in ptr:
        ptr[s] = 0
    print(drink[ptr[s]])
    ptr[s] += 1
