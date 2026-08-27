read fr
read yr
read br
read mr
read sr

read f
read y
read b
read m
read s

cf=$((f / fr))
cy=$((y / yr))
cb=$((b / br))
cm=$((m / mr))
cs=$((s / sr))

ans=$cf
for value in "$cy" "$cb" "$cm" "$cs"; do
    (( value < ans)) && ans=$value
done
echo $ans
