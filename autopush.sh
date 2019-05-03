#!bin/base
$(echo git add .)
$(echo git commit -m "autopushed")
$(echo git push)
$(echo git status)
echo "The push was successful. Hit any key to exit"
read empty
