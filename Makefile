# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 17:01:41 by annabrag          #+#    #+#              #
#    Updated: 2025/03/16 17:03:15 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#—————————————————————————————————————————————
#	ANSI
#—————————————————————————————————————————————

RESET		:=	\033[0m
BOLD		:=	\033[1m
ITAL		:=	\033[3m
BLINK		:=	\033[5m

GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
CYAN		:=	\033[36m
PURPLE		:=	\033[38;2;211;211;255m

#—————————————————————————————————————————————
#	BASE
#—————————————————————————————————————————————

LIBFT_DIR	:=	./LIBFT/
LIBFT		:=	$(addprefix $(LIBFT_DIR), libft.a)
MLX_DIR		:=	./MLX/
MLX			:=	$(addprefix $(MLX_DIR), libmlx.a)

HEADERS		:=	-I ./INCLUDES/ -I/usr/include -I $(MLX_DIR)
BONUS		:=	0

CFLAGS		+=	-Wall -Wextra -Werror
DFLAGS		+=	-MMD -MP
LFLAGS		+=	-L $(LIBFT_DIR) -lft
MLXFLAGS	+=	-L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
LIBFLAGS	+=	$(LFLAGS) $(MLXFLAGS)
DEBUG		+=	-g3 #-03 -0fast

#—————————————————————————————————————————————
#	MANDATORY
#—————————————————————————————————————————————

NAME		:=	cub3D

SRCS_DIR	:=	./SRCS/
SRCS_F		:=	$(sort $(shell find SRCS -type f -name '*.c'))

OBJS_DIR	:=	./OBJS/
OBJS_F		:=	$(patsubst SRCS/%.c,$(OBJS_DIR)%.o,$(SRCS_F))
DEPS_F		:=	$(OBJS_F:.o=.d)

#—————————————————————————————————————————————
#	COMPILATION FUNCTIONS
#—————————————————————————————————————————————

define display_compiled_file
	printf "$(BOLD)$(ITAL)$(1)Compiled: $(RESET)$(ITAL)$(2)\n$(RESET)"
endef

#—————————————————————————————————————————————
#	RULES
#—————————————————————————————————————————————

all: $(OBJS_F) $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		@mkdir -p $(dir $@)
		@$(call display_compiled_file,$(PURPLE),$<)
		@cc $(CFLAGS) $(DFLAGS) -DBONUS=$(BONUS) $(HEADERS) -c $< -o $@
-include $(DEPS_F)

$(LIBFT) $(MLX):
		@make --no-print-directory -sC $(LIBFT_DIR)
		@make --no-print-directory -sC $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS_F) $(LIBFT) $(MLX)
		@echo "\n\n$(BOLD)=================== $(shell bash rainbow.sh "cub3D") $(BOLD)===================\n"
		@echo "$(BLINK)$(GREEN)\t\t    READY!$(RESET)\n"
		@echo "$(BOLD)=============================================$(RESET)\n\n"
		@cc $(CFLAGS) -DBONUS=$(BONUS) $(HEADERS) $(OBJS_F) $(LIBFLAGS) -o $(NAME)

bonus:
		@+$(MAKE) --no-print-directory all BONUS=1 MAKEFLAGS=

clean:
		@rm -rf $(OBJS_DIR)
		@make --no-print-directory clean -sC $(LIBFT_DIR)
		@make --no-print-directory clean -sC $(MLX_DIR) > /dev/null 2>&1
		@echo "\n$(BOLD)$(BLUE)[objects]:\t$(RESET)Removed!"

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(LIBFT) $(MLX)
		@echo "$(BOLD)$(CYAN)[executables]:\t$(RESET)Removed!\n"

re:	fclean all
		@echo "$(BOLD)$(YELLOW)[cub3D] $(RESET)Project successfully rebuilt! ✨\n"

debug: fclean $(LIBFT) $(MLX)
		@make --no-print-directory $(NAME) CFLAGS="$(CFLAGS) $(DEBUG)"

debug_bonus: fclean $(LIBFT) $(MLX)
		@make --no-print-directory $(NAME) CFLAGS="$(CFLAGS) $(DEBUG)" BONUS=1

.PHONY:	all clean fclean re bonus debug debug_bonus