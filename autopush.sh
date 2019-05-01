#!bin/base
$(echo git add .)
read des
$(echo git commit -m "autopushed")
$(echo git push @Kingston2018)
