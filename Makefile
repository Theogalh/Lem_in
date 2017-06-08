##
## Makefile for makefile in /home/theogalh/git/CPE_2015_lemin
## 
## Made by Thomas Bouillon
## Login   <theogalh@epitech.net>
## 
## Started on  Sat Apr 23 21:26:34 2016 Thomas Bouillon
## Last update Sun Apr 24 20:46:04 2016 Robin Partouche
##

CC	=	gcc

SRC	=	src/create_maillon.c \
		src/link_maillon.c \
		src/make_graph.c \
		src/toolgraph.c \
		src/main.c \
		src/check_data.c \
		src/check_file.c \
		src/check_name.c \
		src/list_functions.c \
		src/str_to_wordtab.c \
		src/print_graph.c \
		src/get_node.c \
		src/free_graph.c \
		src/check_coordinate.c \
		src/check_salle_exist.c \
		src/algo.c \
		src/toolnode.c \
		src/pathtool.c \
		src/ant.c \
		src/best_path.c \
		src/keep_path.c \
		src/sort.c \
		src/path_dup.c \

NAME	= 	lem_in

LIBMAKED=	lib/my/libmy.a

LIBROAD	=	-L./lib/

LIB	=	-lmy

OBJ	=	$(SRC:.c=.o)

LIBMAKE	=	lib/my

CFLAGS	=	-c -I./include/ -g -W -Wall -Wextra -ansi -pedantic

LDFLAGS =

all: $(LIBMAKED) $(NAME)

$(LIBMAKED):
	make -C $(LIBMAKE)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBROAD) $(LIB)

clean:
	rm -f $(OBJ) && \
	make -C $(LIBMAKE) clean

fclean: clean
	rm -f $(NAME) && \
	rm -f $(LIBMAKED)

re: fclean all

.PHONY: all clean fclean re
