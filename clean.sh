declare folders
folders=("libs/libft")

for i in "${folders[@]}"
do
	make -C $i fclean
done