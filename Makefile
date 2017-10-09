NAME = fdf

MAKE = make 

MAKE_FLAGS = -C

MAKE_CLEAN = clean

MAKE_FCLEAN = fclean

MAKE_SRC = libft

SRC_DIR = ./srcs

GNL_DIR = ./get_next_line

LIBFT_DIR = ./libft

CC = gcc

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/map_processing.c \
	$(SRC_DIR)/graphic_processing.c \
	$(SRC_DIR)/graphic_processing_2.c \
	$(SRC_DIR)/zoom.c \
	$(SRC_DIR)/height.c \
	$(SRC_DIR)/translation.c \
	$(SRC_DIR)/rotation.c \
	$(GNL_DIR)/get_next_line.c \
	$(SRC_DIR)/rendering.c \
	$(SRC_DIR)/extra.c \
	$(LIBFT_DIR)/libft.a \

OBJ = main.o map_processing.o graphic_processing.o get_next_line.o rendering.o extra.o

OBJ2 = fdf.h.gch


RM = rm -f

all: $(NAME)

$(NAME):
	@echo "---------------------------------------------------------------------"
	@echo "| ffffffffffffffff   DDDDDDDDDDDDD            ffffffffffffffff      |"
	@echo "| f::::::::::::::::f  D::::::::::::DDD        f::::::::::::::::f    |"
	@echo "| f::::::::::::::::::f D:::::::::::::::DD     f::::::::::::::::::f  |"
	@echo "| f::::::fffffff:::::f DDD:::::DDDDD:::::D    f::::::fffffff:::::f  |"
	@echo "| f:::::f       ffffff   D:::::D    D:::::D   f:::::f       ffffff  |"
	@echo "| f:::::f                D:::::D     D:::::D  f:::::f               |"
	@echo "| f:::::::ffffff         D:::::D     D:::::D f:::::::ffffff         |"
	@echo "| f::::::::::::f         D:::::D     D:::::D f::::::::::::f         |"
	@echo "| f::::::::::::f         D:::::D     D:::::D f::::::::::::f         |"
	@echo "| f:::::::ffffff         D:::::D     D:::::D f:::::::ffffff         |"
	@echo "| f:::::f                D:::::D     D:::::D  f:::::f               |"
	@echo "| f:::::f                D:::::D    D:::::D   f:::::f               |"
	@echo "| f:::::::f             DDD:::::DDDDD:::::D   f:::::::f             |"
	@echo "| f:::::::f             D:::::::::::::::DD    f:::::::f             |"
	@echo "| f:::::::f             D::::::::::::DDD      f:::::::f             |"
	@echo "| fffffffff             DDDDDDDDDDDDD         fffffffff             |"
	@echo "---------------------------------------------------------------------"
	@echo "--Compiling libraries--"
	@$(MAKE) $(MAKE_FLAGS) $(MAKE_SRC)
	@echo "--Linking everything---"
	@$(CC) $(FLAG) $(SRC) -o $(NAME)
	@echo "--Done-----------------"

clean:
	@$(MAKE) $(MAKE_CLEAN) $(MAKE_FLAGS) $(MAKE_SRC)
	@$(RM) $(OBJ) $(OBJ2)

fclean: clean
	@$(MAKE) $(MAKE_FCLEAN) $(MAKE_FLAGS) $(MAKE_SRC)
	@$(RM) $(NAME)

re: fclean all
