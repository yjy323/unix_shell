NAME =		minishell

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes
RM =		rm -rf

SRCS_RT_DIR =	srcs/

CFILES =		data/a.c \
				data/b.c \
				data/c.c \
				input/e.c \
				input/d.c \
				input/f.c
CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS_DIR = 		data/ input/
SRCS_DIR :=		$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))
SRCS = $(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = $(SRCS_DIR)

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
