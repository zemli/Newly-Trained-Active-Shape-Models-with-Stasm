#A shell script that will rename all the text files in a directory
#each file will be named with the first line of text from that file

for file in *
do
       
              
              sed '1s/^/}   /' "$file">"$file"      
done

for file in * 
do 
  echo "}" > tem.txt
  cat  tem.txt $file > $file
  #mv tem.txt $file
done

for f in *; do 
  echo "}" > tmpfile
  cat $f >> tmpfile
  mv tmpfile $f
done

#################
awk 'NR % 195 == 0 {sub(/$/,"\n}")} {print}' demo.txt > demo2.txt
#result:1007.72 , 434.58
#1043.36 , 422.56
#}
#2365877276_1
#26.44 , 328.98

#################
awk 'NR % 196 == 2 {sub(/^/,"{ ")} {print}' demo2.txt > demo3.txt
#add {and a space before the first coordinate 
awk 'NR % 196 == 2 {sub(/^/,"{ ")} {print}' demo3.txt > demo4.txt

#delete comma and a space using replace function in sublime

#add 194 2 at first line of matrix
awk 'NR % 196 == 2 {sub(/^/,"{ 194 2\n")} {print}' demo.txt > demo2.txt
awk 'NR % 197 == 3 {gsub(/{ /,"")} {print}' demo2.txt > demo3.txt