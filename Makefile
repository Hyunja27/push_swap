NAME = push_swap
LIBFT = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS =	main.c\
		srcs/list_control.c\
		srcs/basic_action.c\
		srcs/basic_action_2.c\
		srcs/basic_action_3.c\
		srcs/utils.c\

all : $(NAME)

$(NAME) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o $(NAME) $(SRCS)

$(LIB_DIR)/$(LIBFT) :
	@make -C $(LIB_DIR)

re : fclean all

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

test : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft $(SRCS)
	@./a.out
	@rm a.out

.PHONY : test
