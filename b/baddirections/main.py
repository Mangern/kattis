for _ in range(int(input())):
    k,n=input().split()
    k = int(k)
    n = [ord(c)-ord('0') for c in n]
    n = [(i+k)%10 for i in n]
    print("".join(map(str,n)))
