all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -Wall

clean:
	rm ./client