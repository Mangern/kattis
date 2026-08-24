n=int(input())
if n == 1:
    print("*")
    exit()
print(" ".join("*"*n))
for _ in range(n-2):
    print("*"+"  "*(n-2)+" *")
print(" ".join("*"*n))
