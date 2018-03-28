#include <config.h>

#include "actor.h"
#include "frame.h"
#include "screen.h"
#include "inputhandler.h"
#include "gamemap.h"
#include "textconsole.h"

void game_loop(GameMap& map, 
	TextConsole& console,
	InputHandler& input) {

	map.refresh();
	console.refresh();

	int ch;
	while (1) {
		// process input (block; turn based)
		ch = getch();
		if (ch == 'q' || ch == 'Q') exit(0);

		input.handleInput(ch);

		// update game 


		// render game
		map.refresh();
		console.refresh();
	}
}

int main() {
	// Initialize screen using ncurses ////////////////////////
	Screen scr;

	// print a string on screen
	std::string thanks = "Thanks for playing.\n";
	std::string titleinfo = thanks +
		"Press any key to continue.\n" + 
		"Press h for help at any time.\n" +
		"Press q to quit.";
	printw(titleinfo.c_str());

	// starting key press
	int ch = getch();
	if (ch == 'q' || ch == 'Q') return 0;

	// create game map window and output window
	float game_frame_width_ratio = 0.6;
	float output_frame_width_ratio = 1.0 - game_frame_width_ratio;

	Frame game_frame(MAPHEIGHT, 
		MAPWIDTH, 
		0, 0);
	Frame viewport(game_frame, scr.height(), 
		scr.width() * game_frame_width_ratio, 
		0, 0);
	Frame output_frame(scr.height(), 
		scr.width() * output_frame_width_ratio, 
		1, (scr.width() * game_frame_width_ratio) + 1);

	// get mouse input on map frame window
	keypad(viewport.win(), true);
	mousemask(BUTTON1_PRESSED | BUTTON3_PRESSED, NULL);

	// Initialize game objects and map /////////////////////
	// create player actor
	Actor player('@', game_frame.height()/2, game_frame.width()/2);
	GameMap gamemap(game_frame, viewport, player);
	gamemap.loadMap();

	// all handlers
	TextConsole console(output_frame);
	InputHandler input(player, gamemap);

	// enter game loop
	game_loop(gamemap, console, input);
	//game_loop(&player, &game_frame, &viewport, &output_frame);

	return 0;
}