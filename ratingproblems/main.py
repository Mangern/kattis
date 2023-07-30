n,k = map(int,input().split())

s = 0
for i in range(k):
    x = int(input())
    s += x
    
a1 = s + 3*(n-k)
a2 = s - 3 * (n-k)

print(f"{a2/n} {a1/n}")
