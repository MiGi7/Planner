#!bin/base
$(echo git add .)
echo Enter commit statement
read des
$(echo git commit -m $des)
$(echo git push @Kingston2018)
