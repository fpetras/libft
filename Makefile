# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 08:34:49 by fpetras           #+#    #+#              #
#    Updated: 2018/03/22 12:07:20 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libft.a

LIBFT_SRC =			ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strdup.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					\
					ft_memalloc.c \
					ft_memdel.c \
					ft_strnew.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					\
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					\
					ft_abs.c \
					ft_swap.c \
					ft_putwchar.c \
					ft_putwcs.c \
					ft_wcslen.c \
					ft_isspace.c \
					ft_isupper.c \
					ft_islower.c \
					ft_itoa_base.c \
					ft_strlcpy.c \
					ft_strcspn.c \
					ft_strreplace.c \
					ft_atol.c \
					ft_atoll.c

GET_NEXT_LINE_SRC =	get_next_line/get_next_line.c

FT_PRINTF_SRC =		ft_printf/ft_printf.c \
					ft_printf/process_string.c \
					ft_printf/parse_modifiers.c \
					ft_printf/print_decimal.c \
					ft_printf/print_decimal_padding.c \
					ft_printf/print_unsigned_decimal.c \
					ft_printf/print_octal.c \
					ft_printf/print_hexadecimal.c \
					ft_printf/print_pointer.c \
					ft_printf/print_binary.c \
					ft_printf/print_char.c \
					ft_printf/print_control_char.c \
					ft_printf/print_string.c \
					ft_printf/print_percent_sign.c \
					\
					ft_printf/ft_itoa_base_pf.c \
					ft_printf/ft_uitoa_base_pf.c \
					ft_printf/ft_signed_nbr_len.c \
					ft_printf/ft_unsigned_nbr_len.c \
					ft_printf/ft_putwchar_pf.c \
					ft_printf/ft_putwstr_pf.c \
					ft_printf/ft_wstrsize_pf.c

LIBFT_OBJ =			$(LIBFT_SRC:.c=.o)

GET_NEXT_LINE_OBJ =	get_next_line.o

FT_PRINTF_OBJ =		ft_printf.o \
					process_string.o \
					parse_modifiers.o \
					print_decimal.o \
					print_decimal_padding.o \
					print_unsigned_decimal.o \
					print_octal.o \
					print_hexadecimal.o \
					print_pointer.o \
					print_binary.o \
					print_char.o \
					print_control_char.o \
					print_string.o \
					print_percent_sign.o \
					\
					ft_itoa_base_pf.o \
					ft_uitoa_base_pf.o \
					ft_signed_nbr_len.o \
					ft_unsigned_nbr_len.o \
					ft_putwchar_pf.o \
					ft_putwstr_pf.o \
					ft_wstrsize_pf.o

SRC =				$(LIBFT_SRC) $(GET_NEXT_LINE_SRC) $(FT_PRINTF_SRC)

OBJ =				$(LIBFT_OBJ) $(GET_NEXT_LINE_OBJ) $(FT_PRINTF_OBJ)

CC =				gcc

FLAGS =				-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "in progress\n..."
	@$(CC) -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[92mSuccess\033[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
