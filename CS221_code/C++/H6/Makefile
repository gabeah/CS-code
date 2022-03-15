all: test_tree

test_tree: test_tree.o tree.o 
	g++ -g -Wall -Wextra -pedantic -Werror -std=c++17 -c -o $@ $<

%.o: %.cc %.hh
	g++ -g -Wall -Wextra -pedantic -Werror -std=c++17 -O3  -o $@ $<
