NAME		=	libftprintf.a
LIBFT		=	libft.a
CCF			=	@gcc $(CFLAGS)
MKLIB		=	@ar rc
RM			=	@rm -f
CFLAGS		=	-Wall -Wextra -Werror -c
SRCS		=	ft_printf.c frmt_parser.c frmt_print.c print_string.c print_char.c print_ptr.c \
				print_nbr.c print_unbr.c print_hex.c print_none.c print_hex_utils.c print_nbr_utils.c
OBJS		=	$(SRCS:.c=.o)
LIB_DIR		=	./libft/
HDR			=	ft_printf.h

all:		$(NAME)

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)
			@echo objs deleted

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)
			@echo $(NAME) deleted

re:			fclean all

$(NAME):	$(OBJS)
			@make bonus -C $(LIB_DIR)
			@cp $(LIB_DIR)$(LIBFT) $(NAME)
			$(MKLIB) $(NAME) $(OBJS)
			@echo $(NAME) compilled

%.o:		%.c $(HDR)
			$(CCF) -I $(HDR) -o $@ -c $<
			@echo $@ compilled


.PHONY:		all clean fclean re so bonus $(NAME)
