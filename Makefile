NAME =		minishell

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes \
			-I libft/includes

RM =		rm -rf
LIB = -Llibft -lft -lncurses
LINKING_FLAGS = -lreadline -L/opt/homebrew/opt/readline/lib
COMFILE_FLAGS = -I/opt/homebrew/opt/readline/include
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		initialize/ \
				parser/ \
				parser/env_replacer/ \
				parser/tokenizer/ \
				parser/lexer/ \
				parser/syntex_check/ \
				execute/ \
				expand/ \
				execute/ \
				builtin/ \
				hashlib/ \
				variables/ \
				error/ \
				utils/ \
				command/

CFILES =		main.c \
				initialize/initialize.c \
				initialize/signal.c \
				initialize/shtty.c \
				hash/hash_create.c \
				hash/hash_dispose.c \
				hash/hash_shouldgrow.c \
				hash/hash_grow.c \
				hash/hash_buckect.c \
				hash/hash_str_equal.c \
				hash/hash_search.c \
				hash/hash_insert.c \
				hash/hash_remove.c \
				\
				variables/create_variable.c \
				variables/dispose_variable.c \
				variables/bind_variable.c \
				variables/update_export_env.c \
				variables/remove_export_env.c \
				variables/find_export_env.c \
				variables/create_environmet_variable.c \
				variables/valid_environment_variable.c \
				\
				parser/parse.c \
				parser/tokenizer/tokenize.c \
				parser/tokenizer/token_list.c \
				parser/lexer/lex.c \
				parser/lexer/lex_node.c \
				parser/lexer/lex_list.c \
				parser/syntex_check/syntex_check.c \
				expand/expand.c \
				expand/expand_word.c \
				expand/expander.c \
				expand/word_desc_split.c \
				expand/remove_quote_nulls.c \
				\
				command/command.c \
				command/simple_com.c \
				command/connection.c \
				command/word_list.c \
				command/redirect_list.c \
				command/redirect.c \
				command/word_desc.c \
				utils/utils.c \
				\
				execute/execute_command.c \
				execute/execute_connection_command.c \
				execute/execute_simple_command.c \
				execute/do_redirect.c \
				execute/undo_redirect.c \
				\
				builtin/ft_cd.c \
				builtin/ft_echo.c \
				builtin/ft_env.c \
				builtin/ft_exit.c \
				builtin/ft_export.c \
				builtin/ft_pwd.c \
				builtin/ft_unset.c \
				error.c

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} $(COMFILE_FLAGS) -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: make_bonus

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(LINKING_FLAGS) -o $(NAME) $^
	touch $@

make_bonus: $(OBJS_BONUS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(LINKING_FLAGS) -o $(NAME) $^
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
