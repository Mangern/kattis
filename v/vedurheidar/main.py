v = int(input())
for _ in range(int(input())):
    s, x = input().split()
    x = int(x)

    print(s, end=" ")

    if x >= v:
        print("opin")
    else:
        print("lokud")
