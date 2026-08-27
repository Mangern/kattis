import sys

# computes an array "lps" based on the pattern, where
# lps[i] == let s = pattern[0..i] (inclusive), 
#           then lps[i] is the longes proper prefix of s which is also a suffix 
def kmp(pat):
    l = 0 # maintain l, the ans for previous index
    res = [0 for _ in range(len(pat))] #res[0] = 0 because the prefix has to be proper (only 1 character in pat[0..0])
    i = 1
    while i < len(pat):
        if pat[i] == pat[l]: # pat[l] will give the character *after* the longest prefix of last index, 
            l += 1           # so if pat[i] is equal then the length just increases with one
            res[i] = l
            i += 1
        elif l:         
            # we get here, the character at i does not increase the answer from the previous iteration. The next value we should check
            # is the answer for pat[0..l-1] because we know pat[l] != pat[i]. However we cannot be sure the answer for this i is 0 just yet...
            l = res[l-1]
        else:
            # no more values of l to check, simply set the answer to 0
            res[i] = 0
            i += 1
    return res

for pattern in sys.stdin:
    pattern = pattern.strip()
    text = sys.stdin.readline().strip()

    n = len(text)
    m = len(pattern)

    # now we just use the computed lps array in a smart way
    lps = kmp(pattern)
    i = 0
    j = 0
    ans = []

    while i < n or (i == n and j == m):
        if j == m:
            ans.append(i-j)
            j = lps[j-1]
        elif pattern[j] == text[i]:
            i += 1
            j += 1
        elif j > 0:
            # we know everything in pat[0..j-1] matched, however it failed at pat[j]
            # So, because lps[j-1] represents the length of a suffix of pat[0..j-1], this suffix has to be equal 
            # so a suffix of text[0..i-1]
            # so if we just set j to be the length of this suffix (which is also a prefix of pat), j becomes 
            # the earliest possible value in pat that should be compared with index i
            j = lps[j-1]
        else:
            i += 1
    print(" ".join(map(str,ans)))
