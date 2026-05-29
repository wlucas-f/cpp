NAME = Harl

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS_DIR = .
OBJS_DIR = objects

SRCS = main.cpp Harl.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:%.cpp | $(OBJS_DIR)
	c++ $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
