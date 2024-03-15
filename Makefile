# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:38:15 by lquehec           #+#    #+#              #
#    Updated: 2024/03/15 20:27:40 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
					))

# EXIT
SRCS			+=	$(addprefix $(SRCS_DIR)/exit/, $(addsuffix .c, \
					exit \
					))

# PARSING
SRCS			+=	$(addprefix $(SRCS_DIR)/parsing/, $(addsuffix .c, \
					parsing \
					parsing_line \
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
			@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
			@echo "\n${GREEN}> ${NAME} was successfuly compiled 🎉${END}"

$(OBJ_PATH):
			@mkdir -p ${OBJ_PATH}

$(OBJ_PATH)/%.o: %.c
			@mkdir -p $(dir $@)
			@printf "${BLUE}>Generating ${NAME} objects... %-33.33s\r" $@
			@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) -c $< -o $@

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