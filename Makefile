NAME = push_swap
LIBFT = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS =	main.c\
		srcs/list_control.c\
		srcs/list_control_2.c\
		srcs/basic_action.c\
		srcs/basic_action_2.c\
		srcs/basic_action_3.c\
		srcs/utils.c\
		srcs/utils_2.c\
		srcs/utils_3.c\
		srcs/algorithm.c\
		srcs/algorithm_2.c\
		srcs/algorithm_3.c\

B_SRCS = make_checker.c\
		srcs/list_control.c\
		srcs/list_control_2.c\
		srcs/basic_action.c\
		srcs/basic_action_2.c\
		srcs/basic_action_3.c\
		srcs/utils.c\
		srcs/utils_2.c\
		srcs/utils_3.c\
		srcs/algorithm.c\
		srcs/algorithm_2.c\
		srcs/algorithm_3.c\


all : $(NAME)

$(NAME) : $(LIB_DIR)/$(LIBFT) bonus
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o $(NAME) $(SRCS)

$(LIB_DIR)/$(LIBFT) :
	@make -C $(LIB_DIR)

re : fclean all

bonus :
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o checker $(B_SRCS)

clean :
	@rm -rf $(NAME)
	@rm -rf checker
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

test : $(LIB_DIR)/$(LIBFT)
	@rm ./push_swap_visualizer/push_swap
	@make re
	cp push_swap ./push_swap_visualizer

.PHONY : test
