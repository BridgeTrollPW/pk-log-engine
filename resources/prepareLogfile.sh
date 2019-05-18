sed -i 's/<ol class="liveLogs" style="list-style-type:none">//g' $1
sed -i 's/<\/li><li>/\n/g' $1
sed -i 's/<li>/\n/g' $1

