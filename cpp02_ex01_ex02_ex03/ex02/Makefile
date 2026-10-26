NAME := fixed
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp Fixed.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := Fixed.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: Fixed.cpp tests.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) Fixed.cpp tests.cpp -o fixed_tests
	./fixed_tests

clean:
	rm -f $(OBJS) fixed_tests

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re
