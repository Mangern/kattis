import re
art={
"A":
"""Problem A is about Ascii Art
   _     __   __  _   _
  / \   / /  / / | | | |
 / _ \  \ \ | |  | | | |
/_/ \_\ /_/  \_\ |_| |_|
""",
"B":
"""Problem B is about Fortnite
###############
###############
####       /###
####   ########
####       ####
####   ########
####   ########
####   ########
####_~<########
###############
""",
"C":
"""Problem C is about The Legend of Zelda
     /\\
    /  \\
   /____\\
  /\    /\\
 /  \  /  \\
/____\/____\\
"""
}

s=input()
s=re.sub(r"\s", "", s)
m = re.match(r"Whatisproblem([ABC])about\?", s)
if m:
    p=m.group(1)
    print(art[p],end="")
else:
    print("I am not sure how to answer that.")
