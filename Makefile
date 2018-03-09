all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include

debug:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include -Wall -g

clean:
	rm ./client ./debug/*.txt ./core