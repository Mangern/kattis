n=int(input())
k=int(input())
if k >= n:
    print("impossible")
    exit()
for i in range(k):
    print(f"open {i+1} using {i+2}")
