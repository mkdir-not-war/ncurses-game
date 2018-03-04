all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include

debug:
	ulimit -c unlimited
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include -Wall -g

clean:
	rm ./client ./debug/*.txt ./core