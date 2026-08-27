for _ in range(int(input())):
    k=int(input())
    s=input()
    print("".join(chr((ord(c) - ord('A') - k)%26+ord('A')) if ord('A') <= ord(c) <= ord('Z') else c for c in s))
