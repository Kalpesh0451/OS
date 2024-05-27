#!bin/bash
display_menu()
{
echo "MENU"
echo "1.read a file"
echo "2.count char,words and line"
echo "3.reverse the content"
echo "4.frequency of word"
echo "5.exit"
} 

read -p "whats the file name" fname
if [ ! -f "$fname" ]; then
echo "file $fname doesn't exit"
exit 1
fi

while true; do
display_menu
read -p "whats your choice" ch

case $ch in
1)
cat "$fname"
;;

2)
char_count=$(wc -m "$fname")
word_count=$(wc -w "$fname")
line_count=$(wc -l "$fname")
echo "character: $char_count"
echo "words: $word_count"
echo "lines: $line_count"
;; 

3)
rev "$fname"
;;

4)
read -p "enter the words" word
grep -o "\<$word\>" "$fname" | wc -w
;;

5)
echo "exiting"
exit 0
;;

*)
echo "invalide choice"
;;

esac
done
