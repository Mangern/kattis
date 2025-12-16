from sys import stdin
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

for line in stdin:
    for i, tok in enumerate(line.split()):
        if i>0:
            print(" ",end="")
        if tok.isdecimal():
            n=int(tok)
            if n < 20:
                res=low[n]
            elif n % 10 == 0:
                res=f"{tens[n//10]}"
            else:
                res=f"{tens[n//10]}-{low[n%10]}"
            if i==0:
                res = res.capitalize()
            print(res,end="")
        else:
            print(tok,end="")
    print()
