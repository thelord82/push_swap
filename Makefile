# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malord <malord@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:07:57 by malord            #+#    #+#              #
#    Updated: 2022/09/21 16:00:14 by malord           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRCS		=	push_swap.c			\
				swaps.c				\
				rotations.c			\
				rev_rotations.c		\
				errors.c			\
				lists.c				\
				push_moves.c		\
				moves_with_cost.c	\
				utils.c				\
				targets.c			\
				positioning.c

OBJS		= 	${SRCS:.c=.o}

# Targets

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@$(MAKE) -C libft
				@echo "libft compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
				@echo "Done !"

all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@make clean -C libft
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

debug:			all
				$(CC) -g $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

# Removes objects and executable then remakes all
re: 			fclean all
				
.PHONY:			all clean fclean bonus re				