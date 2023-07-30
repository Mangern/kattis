
# 1: Alex, 2: Steve
def brute(n, i=1):
    current_player = ((i+1)&1)+1

    if n == 0:
        return 3 - current_player

    for k in range(1,i+1):
        r = brute(n-k,i+1)
        if r == current_player:
            return current_player
    return 3 - current_player

while True:
    n = int(input())
    r = brute(n)
    print("Alex" if r == 1 else "Steve")
