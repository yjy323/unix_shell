NAME =		minishell

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes -I includes/data -I includes/execute
RM =		rm -rf
LIB = -Llibft -lft -lncurses
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		data/ parse/ execute/ execute/builtin/ execute/operator/

CFILES =		main.c \
				data/token.c \
				data/node.c \
				data/token_list.c \
				data/token_list_action.c \
				data/tree.c \
				data/tree_action.c \
				parse/parse.c \
				parse/tokenize.c \
				parse/lex.c \
				parse/parse_tree.c \
				parse/translate_env.c \
				parse/valid.c \
				execute/execute.c
CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: make_bonus

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $^ -lreadline
	touch $@

make_bonus: $(OBJS_BONUS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $^ -lreadline
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
