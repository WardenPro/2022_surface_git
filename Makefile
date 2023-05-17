# E89 Pedagogical & Technical Lab
# project:     2022_surface_git/
# created on:  Wed May 17 20:07:48 2023
# 1st author:  user
# description: Makefile

NAME	=	surface

SRCS	=	src/main.c			\
		src/set_line.c			\
		src/get_ratio.c			\
		src/get_value.c			\
		src/set_pixel.c			\
		src/clear_pixelarray.c		\
		src/project_paralell.c		\
		src/project_isometric.c		\
		src/surface.c			\
		src/relief.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

save:
	git status
	git add src/*.c include/*.h Makefile
	git commit -m "$(NAME) save"
	git push

exe:
	make re
	./surface
	make fclean

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
