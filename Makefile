# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by pbernier          #+#    #+#              #
#    Updated: 2017/08/07 13:06:40 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	FRACTOL
NAME			=	fractol
BINDIR			=	bin/
SRCDIR			=	src/
SRC				=	fractol.c \
					print_pix.c \
					color.c \
					key.c \
					julia.c \
					mandelbrot.c
SIERRA			=
OBJ				=	$(addprefix $(BINDIR),$(SRC:.c=.o))
LIB				=	libft/libft.a \
					minilibx_macos$(SIERRA)/libmlx.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra
FLAGS_MLX		=	-framework OpenGL -framework AppKit
INCLUDES		=	-I includes/ -I libft/includes/

all: $(NAME)

$(NAME): $(BINDIR) $(OBJ)
	@make -C libft
	@make -C minilibx_macos$(SIERRA)
	@printf "[$(PROJECT)] Bin compilation done.                                                \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS) $(FLAGS_MLX)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(BINDIR):
	@mkdir bin

clean:
	@rm -f $(OBJ)
	@rm -rf $(BINDIR)
	@make -C libft clean
	@make -C minilibx_macos$(SIERRA) clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"


re: fclean all

.PHONY: all clean fclean re
