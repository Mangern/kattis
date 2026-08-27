remap={
"Á": "A",
"á": "a",
"Ð": "D",
"ð": "d",
"É": "E",
"é": "e",
"Í": "I",
"í": "i",
"Ó": "O",
"ó": "o",
"Ú": "U",
"ú": "u",
"Ý": "Y",
"ý": "y",
"Þ": "th",
"þ": "th",
"Æ": "ae",
"æ": "ae",
"Ö": "O",
"ö": "o"
}
s="".join(c if c not in remap else remap[c] for c in input()).lower()
s=[c for c in s if c.isalnum()]
print("".join(s)+".is")
