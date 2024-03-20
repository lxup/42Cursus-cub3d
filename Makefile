# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2024/03/20 11:55:50 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END				=	\033[0m

# COLORS
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m

# FONTS
BOLD			=	\033[1m
DIM				=	\033[2m
UNDERLINED		=	\033[4m
BLINK			=	\033[5m
REVERSE			=	\033[7m

# OS
PLATFORM		=	$(shell uname -s)

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME			=	cub3D

# If OS is windows, add .exe to the name
ifeq ($(OS), Windows_NT)
	NAME := $(addsuffix .exe, $(NAME))
endif
# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC				=	cc
RM				=	rm -rf
MF 				=	Makefile
CFLAGS			=	-Wall -Wextra -Werror -g3 -MMD -MP
ifeq ($(PLATFORM), Darwin)
    CFLAGS		+=	-Imlx
endif

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

INC_PATH		=	includes
OBJ_PATH		=	.obj

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS			+=	-I$(INC_PATH)

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #


SRCS_DIR	= srcs

# SYSTEM
SRCS			=	$(addprefix $(SRCS_DIR)/core/, $(addsuffix .c, \
					main \
					gameplay \
					))

# EXIT
SRCS			+=	$(addprefix $(SRCS_DIR)/exit/, $(addsuffix .c, \
					exit \
					free_game \
					free_map \
					free_parsing \
					free_texture \
					free_win \
					free_image \
					))

# INIT
SRCS			+=	$(addprefix $(SRCS_DIR)/init/, $(addsuffix .c, \
					init \
					init_win \
					init_map \
					init_texture \
					init_image \
					init_vector \
					init_coord \
					))

# PARSING
SRCS			+=	$(addprefix $(SRCS_DIR)/parsing/, $(addsuffix .c, \
					parsing \
					parsing_line \
					parsing_texture \
					parsing_color \
					parsing_map \
					map/parsing_map_check \
					map/parsing_map_create \
					map/parsing_map_leak \
					))

# HOOKS
SRCS			+=	$(addprefix $(SRCS_DIR)/hooks/, $(addsuffix .c, \
					hooks \
					hooks_keyboard \
					hooks_mouse \
					))

# RAYCASTING
SRCS			+=	$(addprefix $(SRCS_DIR)/render/, $(addsuffix .c, \
					render \
					raycasting \
					raycasting_step \
					))

# UTILS
SRCS			+=	$(addprefix $(SRCS_DIR)/utils/, $(addsuffix .c, \
					ft_2d_free \
					ft_2d_putstr \
					ft_2d_size \
					ft_2d_dup \
					ft_print_color \
					ft_color_to_int \
					))

OBJS			=	$(SRCS:%.c=$(OBJ_PATH)/%.o)

DEPS			=	$(OBJS:.o=.d)

# **************************************************************************** #
#                                     LIBS                                     #
# **************************************************************************** #

LDLIBS			=	-lft

# MLX
ifeq ($(PLATFORM), Darwin)
	MLX_DIR 	=	./mlx-opengl
	MLX_FLAGS	=	-framework OpenGL -framework Appkit -lz
	MLX_PATH 	=	$(MLX_DIR)/libmlx.a
else
	MLX_DIR 	=	./mlx-linux
	MLX_FLAGS	=	-lXext -lX11 -lm -lbsd
	MLX_PATH	=	$(MLX_DIR)/libmlx.a
endif
MAKE_MLX		=	make -C $(MLX_DIR)

LDLIBS			+=	-L$(MLX_DIR)

# LIBFT
LIBFT_DIR 		=	libft
LIBFT_INC_PATH	=	$(LIBFT_DIR)/includes
LIBFT			=	$(LIBFT_DIR)/libft.a
MAKE_LIBFT		=	make -C $(LIBFT_DIR)

CFLAGS			+=	-I$(LIBFT_INC_PATH)

LDLIBS			+=	-L$(LIBFT_DIR)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: 		$(NAME)


$(NAME):	${OBJ_PATH} $(OBJS)
			@$(MAKE_LIBFT)
			@$(MAKE_MLX)
			@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME)
			@echo "\n${GREEN}> ${NAME} was successfuly compiled 🎉${END}"

$(OBJ_PATH):
			@mkdir -p ${OBJ_PATH}

$(OBJ_PATH)/%.o: %.c
			@mkdir -p $(dir $@)
			@printf "${BLUE}>Generating ${NAME} objects... %-33.33s\r${END}" $@
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ_PATH)
			@$(MAKE_LIBFT) clean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> All objects files of ${NAME} have been deleted ❌${END}"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE_LIBFT) fclean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> Cleaning of ${NAME} has been done ❌${END}"

re:			fclean all

libft:
			@$(MAKE_LIBFT)

mlx:
			@$(MAKE_MLX)

-include $(DEPS)

.PHONY: all clean fclean re libft mlx