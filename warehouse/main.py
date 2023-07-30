for _ in range(int(input())):
    n = int(input())
    freq = {}
    for i in range(n):
        name,cnt=input().split()
        cnt = int(cnt)
        if name not in freq:
            freq[name] = 0
        freq[name] += cnt
    freq = [(freq[name], name) for name in freq]
    freq.sort(key=lambda t: (-t[0],t[1]))
    print(len(freq))
    for a,b in freq:
        print(b,a)

