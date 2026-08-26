s=input()
if s[:4] == "Til:":
    s=s[4:]
else:
    s=s[3:]
s=s.lstrip()
first=s[:s.find('@')]
part=first.split('+')[0]
last=s[s.find('@'):]
print(f"{part}{last}")
