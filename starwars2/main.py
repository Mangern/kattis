n=int(input())
a = sorted(map(int,input().split()))
b=a[n//3:2*n//3] + a[:n//3] + a[2*n//3:]
print(" ".join(map(str,b)))
