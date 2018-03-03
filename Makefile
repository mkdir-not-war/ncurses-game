all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -Wall -I./include

clean:
	rm ./client