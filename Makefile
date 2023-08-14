NAME =		minishell

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g
INCLUDE = 	-I includes \
			-I libft/includes

RM =		rm -rf
LIB = -Llibft -lft -lncurses
READLINE = -lreadline
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		parser/ execute/ builtin/ hashlib/ variables/

CFILES =		main.c \
				hash/hash_create.c hash/hash_dispose.c hash/hash_shouldgrow.c hash/hash_grow.c \
				hash/hash_buckect.c hash/hash_str_equal.c hash/hash_search.c hash/hash_insert.c hash/hash_remove.c \
				variables/create_variable.c variables/dispose_variable.c variables/bind_variable.c \
				variables/update_export_env.c variables/remove_export_env.c variables/find_export_env.c \
				builtin/ft_cd.c \
				parser/parse.c

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	@if [ ! -d "$(OBJS_DIR)" ]; then mkdir $(OBJS_DIR); fi
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
	$(RM) $(OBJS_DIR)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
