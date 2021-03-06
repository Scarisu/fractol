# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 03:19:16 by pbernier          #+#    #+#              #
#    Updated: 2017/08/09 17:52:36 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	LIBFT
NAME		=	libft.a
BINDIR		=	bin/
SRCDIR		=	src/
SRC			=	ft_putstr.c \
				ft_putchar.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strstr.c \
				ft_strcmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strsplit.c \
				ft_strlcat.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_sqrt.c \
				ft_swap.c \
				ft_range.c \
				ft_strrev.c \
				ft_lstlast.c \
				ft_strjoin_char.c \
				ft_strjoin_clean.c \
				ft_strjoin_clean_char.c \
				ft_absolute.c \
				ft_intlen_base.c \
				ft_puttab.c \
				ft_strtabdel.c \
				ft_itoa_base.c \
				ft_strsplitstr.c \
				ft_intlen_base.c \
				ft_strreset.c \
				ft_llen.c \
				get_next_line.c
OBJ			=	$(addprefix $(BINDIR),$(SRC:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -Ofast

all: $(NAME)

$(NAME): $(BINDIR) $(OBJ)
	@printf "[$(PROJECT)] Bin compilation done.                                               \n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                   \n"

$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "\r[$(PROJECT)] Compiling $< to $@                            \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BINDIR):
	@mkdir bin

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re
