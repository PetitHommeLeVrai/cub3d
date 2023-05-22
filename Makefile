# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:32:06 by mmeguedm          #+#    #+#              #
#    Updated: 2023/05/22 14:13:39 by aboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --------- Prerequisites ------------------------------------------------------

NAME		= cub3d

CC			= cc

# --------- Compilation flags -------------------------------------------------------

CFLAGS		= -Wall -Wextra -I $(INC_PATH) -I $(MLX_PATH) -I $(LIBFT_PATH) -g3
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
L_FLAGS		= -L libft/ -lft

# --------- Include files path ------------------------------------------------------

INC_PATH	= inc/

# --------- Sources files path ------------------------------------------------------

SRC_PATH	= srcs/
MLX_PATH	= ./mlx_linux/
LIBFT_PATH	= ./libft/

# --------- Objects files path ------------------------------------------------------

OBJ_PATH	= obj/

# --------- Header files -----------------------------------------------------------

INC			= $(addprefix $(INC_PATH),		\
				cub3d.h						\
				parsing.h					\
				tools.h						\
				)

# --------- Sources files -----------------------------------------------------------

SRC			=	$(addprefix $(SRC_PATH),					\
					main.c									\
					$(addprefix parsing/,					\
						parse_main.c						\
						error.c								\
					)										\
					$(addprefix exec/,						\
						event_handler.c						\
						init.c								\
						window_handler.c					\
					)										\
				)											\
				$(addprefix get_next_line/,					\
						get_next_line.c						\
						get_next_line_utils.c				\
				)											\

# --------- Object files ------------------------------------------------------------

OBJ			=	$(patsubst srcs/%.c, obj/%.o, $(SRC))

# --------- Compiling ---------------------------------------------------------------

obj/%.o: srcs/%.c $(INC)
	@ mkdir -p $(dir $@)
	@ printf "%-60s\r" "Compiling $<"
	@ $(CC) $(CFLAGS) -c $< -o $@

# --------- Linking -----------------------------------------------------------------

$(NAME) : $(OBJ)
	@mkdir -p $(OBJ_PATH)
	@echo "Compiling MiniLibX..."
	@make -sC $(MLX_PATH)
	@echo "Compiling Libft..."
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(L_FLAGS) -o $(NAME) $(LIBS)
	@printf "\n\n"
	@echo "\033[1;32mCompiling done !"
	@echo "\033[1;36m"
	@cat .cub3d_logo.c
	@echo "\033[0m"

# --------- Phony targets -----------------------------------------------------------

all : $(NAME)

clean :
		rm -rf $(OBJ_PATH)
		@make clean -sC $(MLX_PATH)
		@make clean -sC $(LIBFT_PATH)

fclean : clean
		rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
