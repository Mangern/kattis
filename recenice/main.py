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
bigs=["", "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"]

def tostr(n):
    if n == 0:
        return ""
    if n < 20:
        return low[n]
    if n < 100:
        return f"{tens[n//10]}{tostr(n%10)}"
    return f"{bigs[n//100]}{tostr(n%100)}"

n=int(input())
ws=[input() for _ in range(n)]
srem = sum(len(w) for w in ws if w != "$")
need=0

for i in range(1,1000):
    if srem+len(tostr(i))==i:
        need=i
        break

print(" ".join(tostr(need) if w == '$' else w for w in ws))
