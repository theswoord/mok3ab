


TEST = hh2.c
SRC = main.c utils.c map_related.c drawing.c mlx_related.c math_helper.c map_checks.c parse.c
SRCB = ./bonus_checker/bonus.c ./bonus_checker/instructionpush_bonus.c ./bonus_checker/instructionsrotate_bonus.c ./bonus_checker/instructionsswap_bonus.c ./bonus_checker/output_bonus.c ./bonus_checker/tools_bonus.c ./bonus_checker/instructionhelpers_bonus.c ./bonus_checker/utils2_bonus.c ./bonus_checker/tools2_bonus.c ./bonus_checker/free_bonus.c ./bonus_checker/checker_bonus.c
NAME = cube
NAMEB = checker
CC = gcc

CFLAGS= -Wall -Wextra -Werror  -g -fsanitize=address
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

%.o: %.c
	${CC} -c $< -o $@

test: 
	${CC} ${MLX} -framework Cocoa -framework OpenGL  -framework IOKit ${TEST}


libs: $(SUBDIRS)
	# @echo "\033[1;32mmaking the libs ...\033[0m"

	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) all;)
	# @echo "\033[1;31mit's made \033[0m"
libsre: $(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) re;)
libsclean:	$(SUBDIRS)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)

bonus: ${objb}
	${CC} ${CFLAGS} ${objb} $(libraries) -o $(NAMEB)

rebonus : fcleanbonus bonus

clean : 
	${msa7} ${obj}
cleanbonus : 
	${msa7} ${objb}

fclean : clean libsclean
	${msa7} ${NAME}
fcleanbonus : cleanbonus
	${msa7} ${NAMEB}

re : fclean all
