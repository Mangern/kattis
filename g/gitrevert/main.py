def solve(s, flag=True):
    if not (s.startswith("Revert \"") and s.endswith("\"")):
        return flag
    s = s[8:-1]
    return solve(s,not flag)
s=input().replace('\\\\', '').replace('\\"', '')
print(("un" if solve(s) else "") + "revert")
