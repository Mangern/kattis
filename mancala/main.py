for _ in range(int(input())):
    k,n=map(int,input().split())
    ans = [1,0]
    for i in range(1,n):
        for j,x in enumerate(ans):
            if not x:
                ans[j] = j+1
                break
            else:
                ans[j] -= 1
        if ans[-1]:
            ans.append(0)
    ans.pop()
    print(f"{k} {len(ans)}")
    for i,x in enumerate(ans):
        print(x,end=" ")
        if (i%10==9) or i == len(ans)-1:
            print()
