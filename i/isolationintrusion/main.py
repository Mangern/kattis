n=int(input())
w = [int(input()) for _ in range(3)]
w.sort()
if w[0] + n < w[1]:
    print(w[0] + n)
else:
    print("impossible")
