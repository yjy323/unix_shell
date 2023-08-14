NAME =		minishell

<<<<<<< HEAD
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g
=======
CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
>>>>>>> 513225e93aa3616f49f998471a79e0d847f9cd60
INCLUDE = 	-I includes \
			-I libft/includes

RM =		rm -rf
LIB = -Llibft -lft -lncurses
READLINE = -lreadline
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

<<<<<<< HEAD
SRCS_DIR =		parser/ execute/ builtin/ hashlib/ variables/

CFILES =		main.c \
				hash/hash_create.c hash/hash_dispose.c hash/hash_shouldgrow.c hash/hash_grow.c \
				hash/hash_buckect.c hash/hash_str_equal.c hash/hash_search.c hash/hash_insert.c hash/hash_remove.c \
				variables/create_variable.c variables/dispose_variable.c variables/bind_variable.c \
				variables/update_export_env.c variables/remove_export_env.c variables/find_export_env.c \
				builtin/ft_cd.c \
				parser/parse.c
=======
SRCS_DIR =		parser/ \
				parser/env_replacer/ \
				parser/tokenizer/ \
				parser/lexer/ \
				parser/syntex_check/ \
				execute/ \
				error/ \
				common/

CFILES =		test.c \
				parser/parse.c \
				parser/tokenizer/tokenize.c \
				parser/tokenizer/token_list.c \
				parser/lexer/lex.c \
				parser/lexer/lex_node.c \
				parser/lexer/lex_list.c \
				parser/syntex_check/syntex_check.c \
				common/command.c \
				common/simple_com.c \
				common/connection.c \
				common/word_list.c \
				common/redirect_list.c \
				common/redirect.c \
				common/word_desc.c \
				error.c
>>>>>>> 513225e93aa3616f49f998471a79e0d847f9cd60

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
	$(CC) $(CFLAGS) $(LIB) $(READLINE) -o $(NAME) $^
	touch $@

make_bonus: $(OBJS_BONUS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(READLINE) -o $(NAME) $^
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
