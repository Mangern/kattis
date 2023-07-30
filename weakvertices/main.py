while True:
    n = int(input())
    if n == -1:
        break
    adj = [list(map(int,input().split())) for i in range(n)]
    for i in range(n):
        is_tri = False
        for j in range(n):
            if not adj[i][j]:
                continue
            for k in range(j+1,n):
                if not adj[i][k]:
                    continue
                if adj[j][k]:
                    is_tri = True
                    break
        if not is_tri:
            print(i,end=" ")
    print()
