# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by pbernier          #+#    #+#              #
#    Updated: 2017/08/29 20:15:28 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	FRACTOL
NAME			=	fractol
OBJDIR			=	objs/
SRCDIR			=	srcs/
SRC				=	fractol.c \
					print_pix.c \
					color.c \
					julia/init_julia.c \
					julia/key_julia.c \
					julia/julia.c \
					mandelbrot/init_mandelbrot.c \
					mandelbrot/key_mandelbrot.c \
					mandelbrot/mandelbrot.c \
					mandel_dec/burningship.c \
					mandel_dec/celtic_mandelbrot.c \
					mandel_dec/mandelbar.c \
					mandel_dec/celtic_mandelbar.c \
					mandel_dec/cubic_burningship.c \
					mandel_dec/perpendicular_mandelbrot.c \
					mandel_dec/heart_mandelbrot.c
OBJ				=	$(addprefix $(OBJDIR),$(SRC:.c=.o))
LIB				=	libft/libft.a \
					minilibx_macos/libmlx.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
FLAGS_MLX		=	-framework OpenGL -framework AppKit
INCLUDES		=	-I includes/ -I libft/includes/ -I minilibx_macos/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@printf "[$(PROJECT)] Objs compilation done.                                               \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS) $(FLAGS_MLX)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(OBJDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                                 \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	@mkdir objs
	@mkdir objs/julia
	@mkdir objs/mandelbrot
	@mkdir objs/mandel_dec


clean:
	@rm -f $(OBJ)
	@rm -rf $(BINDIR)
	@make -C libft clean
	@make -C minilibx_macos clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"


re: fclean all

.PHONY: all clean fclean re
