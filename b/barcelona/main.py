n,k=map(int,input().split())
i = list(map(int,input().split())).index(k)

if i == 0:
    print("fyrst")
elif i == 1:
    print("naestfyrst")
else:
    print(i+1,"fyrst")
