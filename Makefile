NAME		= fdf

MLIBX		= lib/minilibx/
GNL			= lib/get_next_line/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)validation.c $(SRC_DIR)utils.c $(SRC_DIR)line.c $(SRC_DIR)init.c \
			$(SRC_DIR)display.c $(SRC_DIR)hooks.c $(SRC_DIR)color.c $(SRC_DIR)get.c $(SRC_DIR)logic.c \
			
OBJ			= $(SRC:%.c=%.o)

MLX_FLAGS	= -L$(MLIBX) -lmlx -lXext -lX11 -lm -lz
LIB_FLAGS	= -L$(GNL) -lgnl -L$(LIBFT) -lft
IFLAG		= -I $(INCLUDES) -I$(LIBFT) -I$(GNL) -I$(MLIBX)
CFLAG		= -Wall -Wextra -Werror #-g3 -fsanitize=address

CC			= cc
AR			= ar rcs
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
					make -C $(LIBFT)
					make -C $(GNL)
					make -C $(MLIBX)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) $(MLX_FLAGS) -o $(NAME)

mainclean:
					$(RM) $(OBJ)
					make -C $(MLIBX) clean

clean:				mainclean
					make -C $(GNL) clean
					make -C $(LIBFT) clean

fclean: 			mainclean
					make -C $(GNL) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all mainclean clean fclean re