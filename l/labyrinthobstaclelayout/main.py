n=int(input())
print("."*n)
for _ in range(n-2):
    print("." + "#"*(n-2)+".")
print("."*n)
