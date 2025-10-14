# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:40:37 by qupollet          #+#    #+#              #
#    Updated: 2025/10/14 18:00:58 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Project
SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes

# Libft
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

# MinilibX
MLX_DIR = minilibx
MLX = ${MLX_DIR}/libmlx.a
# MinilibX flags + math
MLX_FLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm

DEBUG = -g3

SRC =	display/display_window.c \
		display/hooks.c \
		display/load_textures.c \
		display/utils.c \
		game/game.c \
		parsing/backtracking.c \
		parsing/gnl.c \
		parsing/map_read.c \
		parsing/parsing.c \
		parsing/read_paths.c \
		parsing/read_paths2.c \
		parsing/utils.c \
		parsing/verif_utils.c \
		cub3D.c \
		utils.c \
		utils2.c \

SRCS = ${addprefix ${SRC_DIR}/, ${SRC}}
OBJECTS = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}

CC = @cc
CFLAGS = -Wall -Wextra -Werror ${DEBUG}

# Colours
RED = \033[0;91m
GREEN = \033[0;33m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[0m 

all: ${NAME}
	@echo "${GREEN}✅ Executable compiled !"

# Compilation de l'exécutable
${NAME}: ${LIBFT} ${MLX} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${LIBFT} ${MLX_FLAGS}

# Règle pour compiler les fichiers objets dans le dossier objs
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	@echo "${BLUE}   🛠️  Compiling $< into $@...${NC}"
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}  -c $< -o $@

# Création du répertoire objs si non existant
${OBJ_DIR}:
	@echo "${YELLOW}📂 Creating directory ${OBJ_DIR}...${NC}"
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/display
	@mkdir -p ${OBJ_DIR}/game
	@mkdir -p ${OBJ_DIR}/parsing

# Règle pour la compilation de la libft
${LIBFT}:
	@echo "${YELLOW}📦 Compiling libft...${NC}"
	@make -C ${LIBFT_DIR}

# Règle pour la compilation de minilibx
${MLX}:
	@echo "${YELLOW}📦 Compiling minilibx...${NC}"
	@make -C ${MLX_DIR}

# Nettoyage des fichiers objets
clean:
	@echo "${RED}🧹 Cleaning object directory...${NC}"
	@rm -rf ${OBJ_DIR}
	@echo "${RED}🧹 Cleaning libft...${NC}"
	@make clean -C ${LIBFT_DIR}
	@echo "${RED}🧹 Cleaning minilibx...${NC}"
	@make clean -C ${MLX_DIR}

# Nettoyage complet
fclean: clean
	@echo "${RED}🧹 Cleaning executable and objects...${NC}"
	@rm -f ${NAME}
	@rm -f ${LIBFT}
	@rm -f ${MLX}

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re