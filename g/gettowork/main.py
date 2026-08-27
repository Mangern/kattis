for _ in range(int(input())):
    n,t=map(int,input().split())
    t-=1
    sm_pas = [0 for i in range(n)]
    cap = [[] for i in range(n)]

    print(f"Case #{_+1}: ", end="")

    for i in range(int(input())):
        j, p = map(int,input().split())
        j -= 1
        if j == t:
            continue
        sm_pas[j] += 1
        if p:
            cap[j].append(p)
    ans = [0 for i in range(n)]
    sm_cap = [0 for i in range(n)]
    for i in range(n):
        if i == t:
            continue
        cap[i].sort()
        while len(cap[i]) and sm_cap[i] < sm_pas[i]:
            sm_cap[i] += cap[i][-1]
            ans[i] += 1
            cap[i].pop()

        if sm_cap[i] < sm_pas[i]:
            print("IMPOSSIBLE")
            break
    else:
        print(" ".join(map(str,ans)))



