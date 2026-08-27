arr=["leader","intellectual","social","practical"]
for _ in range(int(input())):
    a=list(map(int,input().split()))
    pr=[(sum(1 for x in a if x == k), k-1) for k in range(1,5)]
    print(arr[max(pr)[1]])
