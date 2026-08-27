for _ in range(int(input())):
    print(f"Case #{_+1}: ", end="")
    n,k=map(int, input().split())
    for i in range(n):
        if not (k & (1<<i)):
            print("OFF")
            break
    else:
        print("ON")
    
