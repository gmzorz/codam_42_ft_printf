# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: goosterl <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/02 18:16:32 by goosterl      #+#    #+#                  #
#    Updated: 2020/05/12 12:03:53 by gijsoosterl   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c 		pf_parse_flags.c		\
		pf_utils.c 			pf_parse_char.c			\
		pf_parse_str.c		pf_parse_dash.c			\
 		pf_parse_uint.c		pf_parse_addr.c			\
		pf_parse_perc.c

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libft/
	cp libft/libft.a ./$(NAME)
	gcc -c $(CCFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	make fclean -C ./libft/

%.o: %.c
	gcc $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft/

re: fclean all
