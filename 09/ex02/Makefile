NAME		=	PmergeMe

SRCS		=	main.cpp src/PmergeMe.cpp
				
OBJS		=	$(SRCS:cpp=o)

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98 

INC			=	-I./includes

RM			=	rm -f

all :		$(NAME)

%.o :		%.cpp
		@echo "\n\033[0;33mCompiling $<\033[0m"
		@$(CC) $(INC) $(FLAGS) -c $< -o $(<:cpp=o)
		@echo "\n\033[0;33mCompiling OK!\033[0m"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable\033[0m"
		@$(CC) $(INC) $(CFLAGS) $^ -o $@
		@echo "\n\033[0;33mJob's done!\033[0m"

clean:
		@echo "\033[0;31mCleaning objects..."
		@rm -rf $(OBJS)
		@echo "Cleaned up!\033[0m"
	
fclean:		clean
		@echo "\033[0;31mRemoving executable..."
		@rm -f $(NAME)
		@echo "Removed!\033[0m"

re: 		fclean all

.PHONY: all clean fclean re