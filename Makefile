# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 20:11:37 by caalbert          #+#    #+#              #
#    Updated: 2023/09/18 23:24:36 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                MINIRT                                      ##
################################################################################

NAME  := miniRT
CC    := gcc

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

SRC_DIR   := src/
UI_DIR	  := ui/
INC_DIR   := inc/
LIBFT_DIR := lib/libft/
MLX_DIR   := lib/mlx/
SCENE_DIR := scene/

vpath %.h $(INC_DIR) $(LIBFT_DIR) $(MLX_DIR)
vpath %.c $(SRC_DIR)

LIBFT := $(LIBFT_DIR)libft.a
LIBMLX := $(MLX_DIR)libmlx.a
LIBS := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lm -lXext -lX11

SRCS 	:=	\
			$(SRC_DIR)main.c		\
			$(SRC_DIR)$(UI_DIR)util_canvas.c

OBJS := $(SRCS:.c=.o)

################################################################################
##                                 COMPILATION                                ##
################################################################################

CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS += -Ofast
endif

all: $(NAME)

run: $(NAME)
	@./$(NAME) $(SCENE_DIR)file.rt

valgrind: $(NAME)
	valgrind ./$(NAME) $(SCENE_DIR)file.rt

gdb: $(NAME)
	gdb ./$(NAME)

$(NAME): $(OBJS) | $(LIBFT) $(LIBMLX)
	@$(LOG) "Building $@"
	@$(CC) $^ $(LIBS) -o $@

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(LOG) "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(LIBMLX):
	@make -C $(MLX_DIR) --no-print-directory

clean:
	@$(RM) -r $(OBJS)
	@$(LOG) "Removing objects"
	@make clean -C $(LIBFT_DIR) --no-print-directory --silent
	@make clean -C $(MLX_DIR) --no-print-directory --silent

fclean: clean
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"
	@make fclean -C $(LIBFT_DIR) --no-print-directory --silent

re: fclean all

.PHONY: all run valgrind gdb clean fclean re
