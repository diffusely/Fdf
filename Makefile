NAME		= fdf

MLIBX		= lib/minilibx/
MLIBX_NAME	= $(MLIBX)libmlx.a

GNL			= lib/get_next_line/
GNL_NAME	= -L$(GNL) -lgnl

LIBFT		= lib/libft/
LIBFT_NAME	= -L$(LIBFT) -lft

INCLUDES	= includes

SRC_DIR		= src/

SRC			= main.c

OBJ			= $(SRC:%.c=%.o)

IFLAG		= -I $(INCLUDES)
CFLAG		= -Wall -Wextra -Werror

CC			= cc

AR			= ar rcs

RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) $(CFLAG) $(IFLAG) -Wall -Wextra -Werror -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ) $(GNL_NAME) $(MLIBX_NAME) $(LIBFT_NAME)
					$(CC) $(CFLAG) $^ -o $(NAME) -L/usr/lib -lXext -lX11 -lm -lz

$(GNL_NAME):		
					make -C $(GNL)

$(MLIBX_NAME):
					make -C $(MLIBX)

$(LIBFT_NAME):
					make -C $(LIBFT)

mainclean:
					$(RM) $(OBJ)

clean:				mainclean
					make -C $(GNL) clean
					make -C $(MLIBX) clean
					make -C $(LIBFT) clean

fclean: 			mainclean
					make -C $(GNL) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all mainclean clean fclean re