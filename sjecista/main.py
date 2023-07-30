n = int(input())

s = 0
for i in range(n-2):
    for j in range(i+1):
        s += j

s *= n
s //= 4 
print(s)
