#!bin/base
$(echo git add .)
des="auto_pushed"
read des
$(echo git commit -m $des)
$(echo git push @Kingston2018)
