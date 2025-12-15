NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_LIB) -o $(NAME_CLIENT)

# Bonus rule
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(PRINTF_LIB) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(PRINTF_LIB) -o $(NAME_CLIENT_BONUS)

# Printf library
$(PRINTF_LIB): $(PRINTF_OBJS)
	ar rcs $(PRINTF_LIB) $(PRINTF_OBJS)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	rm -f $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	rm -f $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	rm -f $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re bonus
