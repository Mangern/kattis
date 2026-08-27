read -d ',' first
read -d ' ' tmp
read second
initial=${second:0:1}
initial=${initial@U}

echo "$initial. ${first@u}"
