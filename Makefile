


SRC = main.c utils.c map_related.c drawing.c mlx_related.c math_helper.c map_checks.c parse.c free.c check_map.c errors.c cast_vertical.c cast_horizontal.c map_help.c texture_help.c parse_help2.c parse_help3.c parse_help4.c movements.c texture_help2.c
NAME = cub3D
NAMEB = checker
CC = gcc

CFLAGS= -Wall -Wextra -Werror -Ofast -ffast-math  #-g -fsanitize=address
msa7 = rm -rf
obj = ${SRC:.c=.o}
objb = ${SRCB:.c=.o}
MLX = ./MLX420/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

libraries = ./gnl/gnl.a ./libft/libft.a 
SUBDIRS = gnl libft

.SILENT:
all : libs ${NAME}

${NAME} : ${obj}
	${CC} ${readflag} ${CFLAGS}  ${obj} ${MLX} -framework Cocoa -framework OpenGL -framework IOKit  $(libraries) -o $(NAME)

%.o: %.c cube3d.h
	${CC} -Wall -Wextra -Werror -Ofast -ffast-math -c $< -o $@



libs: $(SUBDIRS)
	# @echo "\033[1;32mmaking the libs ...\033[0m"

	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) all;)
	# @echo "\033[1;31mit's made \033[0m"
libsre: $(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) re;)
libsclean:	$(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)




clean : 
	${msa7} ${obj}

fclean : clean libsclean
	${msa7} ${NAME}

re : fclean all
