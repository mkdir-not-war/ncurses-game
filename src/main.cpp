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
		if (ch == 'q' || ch == 'Q' || ch == KEY_RESIZE) exit(0);

		input.handleInput(ch);

		// update game 
		//TextConsole::print("turn");

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
		"Press q to quit.\n\n\n\n" +
		"WARNING: resizing the window will exit the application.";
	printw(titleinfo.c_str());

	// starting key press
	int ch = getch();
	if (ch == 'q' || ch == 'Q' || ch == KEY_RESIZE) {
		return 0;
	}
	else {
		// clear the title screen away
		clear();
		refresh();
	}

	// create game map window and output window
	float game_frame_width_ratio = 0.5;
	float game_frame_height_ratio = 0.8;
	float output_frame_width_ratio = 1.0 - game_frame_width_ratio;

	Frame game_frame(MAPHEIGHT, 
		MAPWIDTH, 
		0, 0);
	Frame viewport(game_frame, 
		scr.height() * game_frame_height_ratio, 
		scr.width() * game_frame_width_ratio, 
		0, 0);
	Frame output_frame(scr.height(), 
		scr.width() * output_frame_width_ratio, 
		1, (scr.width() * game_frame_width_ratio) + 1);
	/*
	Frame hud_frame(
		scr.height() * (1.0 - game_frame_height_ratio), 
		scr.width() * game_frame_width_ratio, 
		scr.height() * game_frame_height_ratio, 
		0;
	*/

	// get mouse input on map frame window
	keypad(viewport.win(), true);
	mousemask(BUTTON1_PRESSED | BUTTON3_PRESSED, NULL);

	// Initialize game objects and map /////////////////////
	// create player actor
	Actor player('@', 
		game_frame.height()/2, game_frame.width()/2, 
		"The player");
	GameMap gamemap(game_frame, viewport, player);
	gamemap.loadMap();

	// all handlers
	MagicHandler magichandler;
	TextConsole console(output_frame);
	InputHandler input(player, gamemap, magichandler);

	// enter game loop
	game_loop(gamemap, console, input);
	//game_loop(&player, &game_frame, &viewport, &output_frame);

	return 0;
}