read n
res=$(factor $n)
l=${#n}
echo ${res:$((l+2))}
