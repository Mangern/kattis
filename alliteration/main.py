for _ in range(int(input())):
    ws=input().split()
    cnt={}
    for w in ws:
        if w[0] not in cnt:
            cnt[w[0]] = 0
        cnt[w[0]] += 1
    print(min(cnt.items(),key=lambda t:(-t[1],t[0]))[0])

