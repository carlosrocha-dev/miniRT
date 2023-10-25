# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 20:11:37 by caalbert          #+#    #+#              #
#    Updated: 2023/10/22 23:14:43 by caalbert         ###   ########.fr        #
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
OBJ_DIR   := obj/
UI_DIR	  := ui/
INC_DIR   := inc/
LIBFT_DIR := lib/libft/
SCENE_DIR := scene/

vpath %.h $(INC_DIR) $(LIBFT_DIR) $(MLX_DIR)
vpath %.c $(SRC_DIR)

LIBFT := $(LIBFT_DIR)libft.a

LIBS := -L$(LIBFT_DIR) -lft -lm

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLXFLAGS := -lmlx -Ilmlx -lXext -lX11
else
	MLXFLAGS := -L./minilibx/ -lmlx -Ilmlx -L/opt/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

LIBS += $(MLXFLAGS)

SRCS := \
	$(SRC_DIR)main.c \
	$(SRC_DIR)init_objects.c \
	$(SRC_DIR)$(UI_DIR)util_canvas.c \
	$(SRC_DIR)$(UI_DIR)aspect_ratio.c \
	$(SRC_DIR)camera/camera.c \
	$(SRC_DIR)camera/light.c \
	$(SRC_DIR)shapes/sphere.c \
	$(SRC_DIR)tuples/tuple_basic.c \
	$(SRC_DIR)tuples/tuple_operations.c \
	$(SRC_DIR)tuples/tuple_utils.c \
	$(SRC_DIR)validate/scene_validator.c \
	$(SRC_DIR)validate/validate.c

OBJS := $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

################################################################################
##                                 COMPILATION                                ##
################################################################################

CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS += -Ofast
endif

define make-object-directory
	@mkdir -p $(dir $@)
endef

all: $(NAME)

norma:
	@norminette $(SRC_DIR) $(INC_DIR)

test: $(NAME)
	@./$(NAME) $(SCENE_DIR)file.rt

valgrind: $(NAME)
	valgrind ./$(NAME) $(SCENE_DIR)file.rt

gdb: $(NAME)
	gdb ./$(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	@$(LOG) "Building $@"
	@$(CC) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c
	$(call make-object-directory)
	@$(LOG) "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects"
	@make clean -C $(LIBFT_DIR) --no-print-directory --silent

fclean: clean
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"
	@make fclean -C $(LIBFT_DIR) --no-print-directory --silent

re: fclean all

.PHONY: all test valgrind gdb clean fclean re

