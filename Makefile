##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for setting_up
##

CC = epiclang

SRC		=	src/data/extract_data.c \
			src/data/parse_entities.c \
			src/data/parse_script.c \
			src/destroy/destroy_planes.c \
			src/destroy/destroy_radar.c \
			src/destroy/destroy_sprites_and_textures.c \
			src/destroy/destroy_towers.c \
			src/events/analyse_events.c \
			src/events/calculate_angle.c \
			src/events/get_timer.c \
			src/planes/check_planes.c \
			src/planes/init_planes.c \
			src/planes/move_planes.c \
			src/planes/parse_planes.c \
			src/planes/planes_collision.c \
			src/planes/update_planes.c \
			src/sprites/display_all.c \
			src/sprites/init_all.c \
			src/sprites/sprites.c \
			src/towers/init_towers.c \
			src/towers/parse_towers.c \
			src/window/loop_window.c \
			src/window/open_window.c \
			src/main.c

OBJ		= 	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	= 	-Wall -Wextra -I./include

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -lm $(CFLAGS) $(CSFML)

clean:
	$(MAKE) -C ./lib/my clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all
