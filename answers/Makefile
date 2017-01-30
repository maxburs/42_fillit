NAME = fillit

LIBA = ./libft/libft.a

OBJS = \
	fillit.o\
	global_init.o\
	piece_mask.o\
	init_pieces_points.o\
	g_minos.o\
	input_parse.o\
	solve.o\
	helper.o\
	solve_recursion.o\
	string_not_val.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -I . -I libft -o $@ $<

$(NAME): $(OBJS) $(LIBA)
	gcc -o $@ $^

$(OBJS): fillit.h

$(LIBA):
	cd libft && $(MAKE)

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: clean all
