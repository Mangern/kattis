low=[
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
]
tens=["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

def conv(n, flag=False):
    if flag and n == 0:
        return ""
    if n < len(low):
        return low[n]

    if n < 100:
        return f"{tens[n//10]}{''if n%10==0 else '-'+conv(n%10,True)}"
    elif n < 1000:
        ts = n//100
        rem = n % 100
        return f"{low[ts]} hundred {conv(rem, True)}"
    elif n < 1000000:
        ts = n//1000
        rem = n % 1000
        return f"{conv(ts)} thousand {conv(rem, True)}"
    else:
        ts = n//1000000
        rem = n % 1000000
        return f"{low[ts]} million {conv(rem, True)}"

for _ in range(int(input())):
    n=int(input())
    if n < 0:
        print("negative ",end="")
        n *= -1
    print(conv(n))
