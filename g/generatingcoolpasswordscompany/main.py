n=int(input())
for i in range(n):
    psw = [33]*8
    x = i
    for j in range(4):
        psw[2*j] += x % 10
        psw[2*j+1] += x % 10
        x //= 10
    print("aA0!" + "".join(map(chr,psw)))
