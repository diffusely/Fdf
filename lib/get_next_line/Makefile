NAME 		= libgnl.a

SRC 		= get_next_line.c get_next_line_utils.c

INCLUDES 	= ../libft

CFLAG 		= -Wall -Wextra -Werror -I $(INCLUDES)

CC 			= cc

RM			= rm -rf

AR			= ar rcs

OBJ			= $(SRC:%.c=%.o)


%.o:		%.c Makefile
			$(CC) $(CFLAG) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) 
			$(AR) $(NAME) $^

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re