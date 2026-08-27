r,c,n=map(int,input().split())

occu = set(tuple(map(int,input().split())) for _ in range(n))

ans = 1
while True:
    to_add = set()
    for i,j in occu:
        for ni,nj in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
            if 1 <= ni <= r and 1 <= nj <= c and (ni,nj) not in occu:
                to_add.add((ni,nj))
    if len(to_add) == 0:
        break
    ans += 1
    occu = occu.union(to_add)

print(ans)

