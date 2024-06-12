def main():
    n = int(input())

    cnt = 1
    ans = []
    for i, x in enumerate(map(int, input().split())):
        if i == 0:
            ans.append(x)
        elif x > ans[-1]:
            cnt += 1
            ans.append(x)
    print(cnt)
    print(" ".join(map(str, ans)))

main()

