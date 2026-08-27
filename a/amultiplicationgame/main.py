from sys import stdin

def main():
    dp = {}
    def win(p, n):
        if (p,n) in dp:
            return dp[(p,n)]
        if p >= n:
            return True
        for k in range(2,10):
            if win(p * k, n):
                dp[(p,n)] = False
                return False
        dp[(p,n)] = True
        return True

    for line in stdin:
        print("Ollie" if win(1, int(line)) else "Stan", "wins.")

main()
