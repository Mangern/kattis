s = str(int(input()))
ans = 1

for l in range(1, len(s)):
    ans += 2**(l-1)

# How many of length exactly len(s)?
if int(s[0]) > 2:
    ans += 2**(len(s) - 1)
elif int(s[0]) == 2:
    count = len(s) - 1

    for i in range(1, len(s)):
        if int(s[i]) > 2:
            ans += 2**count
            break
        elif int(s[i]) == 2:
            # Putting 0 here yields 2**(count-1)
            # for the remaining
            # Putting 2 we have to look further
            ans += 2**(count-1)
        elif int(s[i]) == 1:
            # Forced to put 0, but after that everything is legal
            ans += 2**(count-1)
            break
        else:
            # Forced to put 0, and we must look further
            pass
        count -= 1
    else:
        # We looked all the way?
        ans += 1


print(ans)
