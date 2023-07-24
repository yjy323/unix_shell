NAME =		minishell

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes -I includes/execute
RM =		rm -rf
LIB = -Llibft -lft -lncurses
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		execute/ execute/command/ execute/operator/ \
				builtin/

CFILES =		main.c \
				execute/execute.c \
				execute/command/exec_command.c \
				execute/command/exec_redirect.c \
				execute/operator/operate_pipe.c \
				execute/operator/operate_single_command.c \
				execute/operator/sub_process_wait.c \
				execute/operator/sub_process_add_lst.c \
				execute/operator/is_first_operate_cmd.c \
				execute/operator/is_last_operate_cmd.c \
				builtin/ft_cd.c \
				builtin/ft_echo.c \
				builtin/ft_env.c \
				builtin/ft_exit.c \
				builtin/ft_export.c \
				builtin/ft_pwd.c \
				builtin/ft_unset.c
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
