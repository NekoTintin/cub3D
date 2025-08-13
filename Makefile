# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:40:37 by qupollet          #+#    #+#              #
#    Updated: 2025/07/31 17:54:49 by qupollet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = include

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBS = -I/minilibx -Imlx_linux
DEBUG = -g3

SRC =	cub3D.c \
		utils.c \

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
${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${LIBFT}

# Règle pour compiler les fichiers objets dans le dossier objs
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	@echo "${BLUE}   🛠️  Compiling $< into $@...${NC}"
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}  -c $< -o $@

# Création du répertoire objs si non existant
${OBJ_DIR}:
	@echo "${YELLOW}📂 Creating directory ${OBJ_DIR}...${NC}"
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/parsing

# Règle pour la compilation de la libft
${LIBFT}:
	@echo "${YELLOW}📦 Compiling libft...${NC}"
	@make -C ${LIBFT_DIR}

# Règle pour la compilation de minilibx
minilibx:
	@echo "${YELLOW}📦 Compiling minilibx...${NC}"
	@make -C minilibx

# Nettoyage des fichiers objets
clean:
	@echo "${RED}🧹 Cleaning object directory...${NC}"
	@rm -rf ${OBJ_DIR}
	@echo "${RED}🧹 Cleaning libft...${NC}"
	@make clean -C ${LIBFT_DIR}

# Nettoyage complet
fclean: clean
	@echo "${RED}🧹 Cleaning executable...${NC}"
	@rm -f ${NAME}
	@rm -rf ${OBJ_DIR}
	@make fclean -C ${LIBFT_DIR}

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re