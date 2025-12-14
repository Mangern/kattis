for _ in range(int(input())):
    n = int(input())
    s=f"{n*n}"

    for i in range(len(s)):
        lft=int(s[:i+1])
        rgt= 0 if i == len(s)-1 else int(s[i+1:])
        if lft+rgt==n and rgt != 0 or s == "1":
            print("YES")
            break
    else:
        print("NO")
