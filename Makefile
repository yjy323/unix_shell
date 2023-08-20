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

SRCS_DIR =		signal/ \
				parser/ \
				parser/env_replacer/ \
				parser/tokenizer/ \
				parser/lexer/ \
				parser/syntex_check/ \
				execute/ \
				expand/ \
				error/ \
				utils/ \
				common/

CFILES =		main.c \
				signal/sig_handler.c \
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
				common/command.c \
				common/simple_com.c \
				common/connection.c \
				common/word_list.c \
				common/redirect_list.c \
				common/redirect.c \
				common/word_desc.c \
				utils/utils.c

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
