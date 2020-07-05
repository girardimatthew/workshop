# convert file .HEIC to .jpg
i=0
for file in *.HEIC
do
magick convert -verbose "$file" PIC_$i.jpg
i=$((i + 1))
done

# remove all file with HEIC extension
# rm -rf *.HEIC