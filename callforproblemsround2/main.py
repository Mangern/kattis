n,k=map(int,input().split())
s=set(map(int, [input() for _ in range(n)]))
print(min(k,len(s)))
