n=int(input())
n //= 5
k=n//3
s=-3*k+6*k*(k+1)
if n % 3 >= 1:
    s += 4 * (k + 1) - 2
if n % 3 >= 2:
    s += 4 * (k + 1) - 1
s *= 4
s += 1
print(s)
