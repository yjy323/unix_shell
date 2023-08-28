NAME =		minishell

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes \
			-I libft/includes \
			-I readline/include
RM =		rm -rf
LIB = -Llibft -lft -Lreadline/lib -lreadline -lhistory
BUILD_LIBFT = make -C libft $@
BUILD_REALINE = make -C readline $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		prompt/ \
				parse/ \
				parse/env_replacer/ \
				parse/tokenize/ \
				parse/lex/ \
				parse/standardize/ \
				parse/syntex_check/ \
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
				prompt.h/initialize.c \
				prompt.h/destroy.c \
				prompt.h/signal.c \
				prompt.h/signal_handler.c \
				prompt.h/shtty.c \
				prompt.h/shell.c \
				prompt.h/clear_tmp.c \
				\
				hash/hash_create.c \
				hash/hash_dispose.c \
				hash/hash_shouldgrow.c \
				hash/hash_grow.c \
				hash/hash_buckect.c \
				hash/hash_str_equal.c \
				hash/hash_search.c \
				hash/hash_insert.c \
				hash/hash_remove.c \
				hash/hash_search_variable_value.c \
				\
				variables/init_sh_variable.c \
				variables/clear_sh_variable.c \
				variables/create_variable.c \
				variables/dispose_variable.c \
				variables/bind_variable.c \
				variables/update_export_env.c \
				variables/remove_export_env.c \
				variables/find_export_env.c \
				variables/create_environment_variable.c \
				varables/destroy_environment_variable.c \
				\
				parse/parse.c \
				parse/tokenize/tokenize.c \
				parse/tokenize/token_list.c \
				parse/lex/lex.c \
				parse/lex/lex_node.c \
				parse/lex/lex_list.c \
				parse/standardize/standardize.c \
				parse/standardize/syntex_check.c \
				parse/standardize/standardize.c \
				parse/syntex_check/syntex_check.c \
				expand/expand_heredoc.c \
				expand/expand_words.c \
				expand/exapnd_hashdollor.c \
				expand/expand_word.c \
				expand/expander.c \
				expand/word_desc_split.c \
				expand/remove_quote_nulls.c \
				heredoc/heredoc.c \
				\
				command/command.c \
				command/simple_com.c \
				command/connection.c \
				command/word_list.c \
				command/redirect_list.c \
				command/redirect.c \
				command/word_desc.c \
				utils/xalloc.c \
				utils/xstr.c \
				\
				execute/execute_command.c \
				execute/execute_connection_command.c \
				execute/execute_simple_command.c \
				execute/execute_filesystem.c \
				execute/execute_builtin.c \
				execute/do_redirect.c \
				execute/undo_redirect.c \
				execute/get_redir_flag.c \
				execute/do_pipe_redirect.c \
				execute/job_control.c \
				\
				builtin/ft_cd.c \
				builtin/ft_echo.c \
				builtin/ft_env.c \
				builtin/ft_exit.c \
				builtin/ft_export.c \
				builtin/ft_pwd.c \
				builtin/ft_unset.c \
				builtin/valid_environ_convention.c \
				error/crash.c \
				error/exception_handler.c \
				error/exception_handler_sub_ps.c \
				error/print_error_msg.c

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_readline make_mandatory

all: $(NAME)

bonus: all

make_readline:
	make -C readline

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $^
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)
	$(BUILD_REALINE)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)
	$(BUILD_REALINE)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
