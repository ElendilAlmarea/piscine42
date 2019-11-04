cat /etc/passwd | grep -v \# | cut -d \* -f 1 | cut -d : -f -1 | sed -n 'n;p' | rev | sort -r | sed -n -e "$FT_LINE1,${FT_LINE2}p" | xargs | sed 's/ /, /g' | sed '/:[0-9]*$/ ! s/$/./' | tr -d '\n'
