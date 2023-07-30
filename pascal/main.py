n = int(input())

i = 2
mx = 1
while i * i <= n:
    if n % i == 0:
        mx = n//i
        break
    i += 1

print(n - mx)
