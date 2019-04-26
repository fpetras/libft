# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 08:34:49 by fpetras           #+#    #+#              #
#    Updated: 2019/04/10 12:01:23 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcspn.c \
			ft_strcmp.c ft_strncmp.c ft_strcasecmp.c ft_strncasecmp.c \
			ft_atoi.c ft_atol.c ft_atoll.c \
			ft_isalpha.c ft_isdigit.c ft_isxdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_isspace.c ft_isupper.c ft_islower.c \
			ft_toupper.c ft_tolower.c \
			\
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strequ.c ft_strnequ.c \
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_strreplace.c \
			ft_itoa.c ft_itoa_base.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putwchar.c ft_putwcs.c ft_wcslen.c \
			\
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
			ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			\
			ft_abs.c \
			ft_swap.c \
			ft_calloc.c \
			\
			ft_strupr.c ft_strlwr.c

GET_NEXT_LINE_PATH = get_next_line/
GET_NEXT_LINE_SRC =	get_next_line.c

FT_PRINTF_PATH = ft_printf/
FT_PRINTF_SRC = ft_printf.c \
				process_string.c parse_modifiers.c \
				print_decimal.c print_decimal_padding.c \
				print_unsigned_decimal.c \
				print_octal.c print_hexadecimal.c print_pointer.c \
				print_binary.c \
				print_char.c print_control_char.c print_string.c \
				print_percent_sign.c \
				\
				ft_itoa_base_pf.c ft_uitoa_base_pf.c \
				ft_signed_nbr_len.c ft_unsigned_nbr_len.c \
				ft_putwchar_pf.c ft_putwstr_pf.c ft_wstrsize_pf.c

OBJ += $(LIBFT_SRC:.c=.o)
OBJ += $(addprefix $(GET_NEXT_LINE_PATH),$(GET_NEXT_LINE_SRC:.c=.o))
OBJ += $(addprefix $(FT_PRINTF_PATH),$(FT_PRINTF_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLEAR_LINE = \033[2K\c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CLEAR_LINE)"
	@echo "Creating $@"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "$(CLEAR_LINE)"
	@echo "Compiling $<\r\c"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
