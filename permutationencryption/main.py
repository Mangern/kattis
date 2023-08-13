while True:
    l = list(map(int,input().split()))
    n = l[0]
    if not n:
        break
    a = [x-1 for x in l[1:]]

    s = list(input())

    while (len(s) % n) != 0:
        s.append(' ')

    ans = [' ' for i in s]
    
    for i,c in enumerate(s):
        k = (i//n)
        c = s[k*n+a[i%n]]
        ans[i] = c

    print("'" + "".join(ans) + "'")
