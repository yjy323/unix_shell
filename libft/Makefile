NAME =		libft.a

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
AR =		ar -rcus
RM =		rm -rf
INCLUDE = 	-I includes

FILES =		ft_isalpha \
			ft_isalnum \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_tolower \
			ft_toupper \
			ft_strlen \
			ft_strlcpy \
			ft_strlcat \
			ft_strncmp \
			ft_strnstr \
			ft_strchr \
			ft_strrchr \
			ft_strdup \
			ft_memset \
			ft_memcpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_bzero \
			ft_calloc \
			ft_atoi \
			ft_substr \
			ft_strjoin \
			ft_strmapi \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd

FILES_BONUS	=	ft_lstnew \
				ft_lstadd_front \
				ft_lstadd_back \
				ft_lstsize \
				ft_lstlast \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap

SRCS_DIR = 		srcs/
SRCS =  		$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_BONUS)))

OBJS_DIR = 		objs/
OBJS =  		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_BONUS)))

$(OBJS_DIR)%o: $(SRCS_DIR)%c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): all

all: make_mandatory

bonus: make_bonus

make_mandatory: $(OBJS)
	$(AR) $(NAME) $^
	touch $@

make_bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $^
	touch make_mandatory
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
