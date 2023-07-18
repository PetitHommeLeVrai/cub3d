# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:32:06 by mmeguedm          #+#    #+#              #
#    Updated: 2023/07/18 17:25:14 by mmeguedm         ###   ########.fr        #
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
						main_parsing.c						\
						parse_ftc.c							\
						get_map.c							\
						get_texture.c						\
						get_colors.c						\
						init_geo.c							\
						fill_colors.c						\
						utils.c								\
						error.c								\
						parse_map.c							\
					)										\
					$(addprefix exec/,						\
						event_handler.c						\
						key_move.c							\
						key_rotate.c						\
						free.c								\
						init_mlx.c							\
						init.c								\
						window_handler.c					\
					)										\
					$(addprefix get_next_line/,				\
						get_next_line.c						\
						get_next_line_utils.c				\
					)										\
					$(addprefix graphics/,					\
						draw_map.c							\
						calcul.c							\
						ray.c								\
					)										\
				)											\

# --------- Object files ------------------------------------------------------------

OBJ			=	$(patsubst srcs/%.c, obj/%.o, $(SRC))

# --------- Compiling ---------------------------------------------------------------

obj/%.o: srcs/%.c $(INC)
	@ mkdir -p $(dir $@)
	@ printf "\033[1;32m%-60s\r" "Compiling $<"
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
		@echo "Deleting all objects files..."
		@rm -rf $(OBJ_PATH)
		@make clean -sC $(MLX_PATH)
		@make clean -sC $(LIBFT_PATH)
		@echo "\033[1;32mCleaning done !"
		@echo "\033[1;36m"

fclean : clean
		@echo "Deleting $(NAME)..."
		@rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
