NAME		= fdf

MLIBX		= minilibx/
MLIBX_NAME	= $(MLIBX)libmlx.a

GNL			= get_next_line/
GNL_NAME	= $(GNL)libgnl.a

INCLUDES	= includes

SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)test.c

OBJ			= $(SRC:%.c=%.o)

IFLAG		= -I $(INCLUDES)
CFLAG		= -Wall -Wextra -Werror

CC			= cc

AR			= ar rcs

RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) $(CFLAG) $(IFLAG) -Wall -Wextra -Werror -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ) $(GNL_NAME) $(MLIBX_NAME)
					$(CC) $(CFLAG) $^ -o $(NAME) -L/usr/lib -lXext -lX11 -lm -lz

$(GNL_NAME):		
					make -C $(GNL)

$(MLIBX_NAME):
					make -C $(MLIBX)

mainclean:
					$(RM) $(OBJ)

clean:				mainclean
					make -C $(GNL) clean
					make -C $(MLIBX) clean

fclean: 			mainclean
					make -C $(GNL) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all mainclean clean fclean re