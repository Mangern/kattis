nxt = [
    [],
    [2,4],
    [3,5],
    [6],
    [5,7],
    [6,8],
    [9],
    [8],
    [0,9],
    []
]
def generate(all, num = 1, cur = 0):
    if cur > 200:
        return
    cur2 = cur * 10 + num
    all.append(cur2)

    if cur2 != 0:
        generate(all, num, cur2)
    for n in nxt[num]:
        generate(all, n, cur)
        generate(all, n, cur2)

def main():
    all = []
    generate(all)
    for _ in range(int(input())):
        k = int(input())
        mini = 10**9
        for x in all:
            if abs(x - k) < abs(mini - k):
                mini = x
        print(mini)



main()
