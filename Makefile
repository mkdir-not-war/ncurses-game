all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include

clean:
	rm ./client