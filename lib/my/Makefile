##
## Makefile for  in /home/partou_a/rendu/Piscine_C_J10/lib/my
## 
## Made by Robin Partouche
## Login   <partou_a@epitech.net>
## 
## Started on  Fri Oct  9 11:21:51 2015 Robin Partouche
## Last update Mon Apr 18 22:17:26 2016 thomas
##

SRC	=	my_8r1.c \
		my_aff_alpha.c \
		my_aff_chiffre.c \
		my_aff_comb2.c \
		my_aff_comb.c \
		my_aff_revalpha.c \
		my_evil_str.c \
		my_factorielle_rec.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_show_wordtab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
                my_power_it.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		sum_params.c \
		my_put_in_list.c \
		my_puterr.c \
		my_printf.c \
		my_put_printf.c \
		my_search_printf.c \
		my_search_printf2.c \
		my_search_printf3.c \
		my_xmalloc.c \
		get_next_line.c \

NAME	= 	../libmy.a

NAMELIB	=	libmy.a

OBJ	= 	$(SRC:.c=.o)

HEAD	= 	my.h \
		mylist.h \
		get_next_line.h \

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)
	mv $(NAMELIB) ../
	cp $(HEAD) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
