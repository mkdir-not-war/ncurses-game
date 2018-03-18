
WINLIBS = -lpdcurses -lws2_32 -std=c++11 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
INCLUDE = -I./include -I./

all:
	g++ -std=c++11 ./src/*.cpp -o ./bin/client -lncurses -I./include

debug:
	g++ -std=c++11 ./src/*.cpp -o ./bin/client -lncurses -I./include -Wall -g

win:
	x86_64-w64-mingw32-g++-posix ./src/*.cpp -o ./bin/client.exe $(INCLUDE) $(WINLIBS)

zip:
	zip ../gavin-project ./client

zipwin:
	zip ../gavin-project ./client.exe

clean:
	rm ./bin/client ./bin/client.exe ./debug/*.txt ./core
