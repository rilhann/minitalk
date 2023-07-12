SRCS_SV = server.c
SRCS_CL = client.c
SRCS_BSV = server_bonus.c
SRCS_BCL = client_bonus.c
SRCS = ft_printf.c ft_atoi.c
OBJS_SRCS = $(SRCS:.c=.o)
OBJS_SV = $(SRCS_SV:.c=.o) $(OBJS_SRCS)
OBJS_CL = $(SRCS_CL:.c=.o) $(OBJS_SRCS)
OBJS_BSV = $(SRCS_BSV:.c=.o) $(OBJS_SRCS)
OBJS_BCL = $(SRCS_BCL:.c=.o) $(OBJS_SRCS)
NAME_SV = server
NAME_CL = client
NAME_BSV = server_bonus
NAME_BCL = client_bonus
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SV) $(NAME_CL)

$(NAME_SV): $(OBJS_SV)
	gcc $(CFLAGS) $(OBJS_SV) -o $(NAME_SV)

$(NAME_CL): $(OBJS_CL)
	gcc $(CFLAGS) $(OBJS_CL) -o $(NAME_CL)

$(NAME_BSV): $(OBJS_BSV)
	gcc $(CFLAGS) $(OBJS_BSV) -o $(NAME_BSV)

$(NAME_BCL): $(OBJS_BCL)
	gcc $(CFLAGS) $(OBJS_BCL) -o $(NAME_BCL)

bonus: $(NAME_BSV) $(NAME_BCL)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_SV) $(OBJS_CL) $(OBJS_BSV) $(OBJS_BCL) $(OBJS_SRCS)

fclean: clean
	rm -rf $(NAME_SV) $(NAME_CL) $(NAME_BSV) $(NAME_BCL)

re: fclean all

.PHONY: all clean fclean re