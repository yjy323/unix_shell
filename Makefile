NAME =		minishell

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes
RM =		rm -rf
LIB = -Llibft -lft -lncurses
BUILD_LIBFT = make -C libft $@

SRCS_DIR =	srcs/

CFILES =		main.c
CFILES :=		$(addprefix $(SRCS_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%o: $(CFILES)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: make_bonus

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $^
	touch $@

make_bonus: $(OBJS_BONUS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $^
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
