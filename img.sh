

for jp in images/*.*; do
 convert "$jp" -thumbnail 640x440 PIMG.jpeg
 convert PIMG.jpeg -thumbnail 134x92 THMB.jpeg
 echo $(basename "${jp%%.*}")
 ./nickjiggler $(basename "${jp%%.*}" )
 mv *.jig custom/
 rm PIMG.jpeg THMB.jpeg
done
