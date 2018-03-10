
WINLIBS = -lpdcurses -lws2_32 -std=c++11 -static-libgcc -static-libstdc++ -pthread
WINLESSLIBS = -lpdcurses -lws2_32 -std=c++11
INCLUDE = -I./include -I./

all:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include

debug:
	g++ -std=c++11 ./src/*.cpp -o client -lncurses -I./include -Wall -g

win:
	x86_64-w64-mingw32-g++-posix ./src/*.cpp -o client.exe $(INCLUDE) $(WINLIBS)

win2:
	x86_64-w64-mingw32-g++-posix ./src/*.cpp -o client.exe $(INCLUDE) $(WINLESSLIBS)

zip:
	zip ../gavin-project ./client

zipwin:
	zip ../gavin-project ./client.exe

clean:
	rm ./client ./client.exe ./debug/*.txt ./core
