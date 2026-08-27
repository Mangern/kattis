ws=set(["h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"])

for _ in range(int(input())):
    s=input()
    n=len(s)
    can=[False]*(n+1)
    can[0] = True

    for i in range(1, n+1):
        for l in range(1,min(3,i+1)):
            w = s[:i][-l:]
            if w in ws:
                can[i] = can[i] or can[i-l]
    print("YES" if can[n] else "NO")
