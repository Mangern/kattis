n=int(input())
a = 1
while a * (a + 1) * (a + 2) < n:
    a += 1
print(a-1)
