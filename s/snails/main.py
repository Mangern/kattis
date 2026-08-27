for _ in range(int(input())):
    a = list(map(int,input().split()))
    if a[:4] != [0,1,2,3][:min(4,len(a))]:
        print("SNAIL")
        continue
    for i in range(4,len(a)):
        if a[i-4]+a[i-3]+a[i-2]+a[i-1] != a[i]:
            print("SNAIL")
            break
    else:
        print("NAUTILUS")
