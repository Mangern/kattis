def main():
    digits = "0123456789ACDEFHJKLMNPRTVWX"
    coef = [2,4,5,7,8,10,11,13]

    confuse = {
        "B": "8",
        "G": "C",
        "I": "1",
        "O": "0",
        "Q": "0",
        "S": "5",
        "U": "V",
        "Y": "V",
        "Z": "2"
    }

    def get_dig(c):
        if c in confuse:
            c = confuse[c]
        return digits.index(c)

    for _ in range(int(input())):
        k,s=input().split()
        print(k, end=" ")

        vals = [get_dig(c) for c in s[:8]]
        x = sum(a*b for a,b in zip(coef, vals))%27
        if digits[x%27] != s[8]:
            print("Invalid")
        else:
            mul = 1
            ans = 0
            for x in vals[::-1]:
                ans += mul * x
                mul *= 27
            print(ans)
main()
