#include <ncurses.h>

#include "actor.h"
#include "frame.h"
#include "screen.h"
#include "inputhandler.h"

void game_loop(Frame& game_map, Frame& viewport, 
	Actor& player, int ch) {

	if (ch == 'q' || ch == 'Q') return;

	game_map.add(player);
	viewport.center(player);
	viewport.refresh();

	InputHandler input(&player, &viewport);

	while (1) {
		// process input (block; turn based)
		ch = getch();
		input.handleInput(ch);

		// update game 


		// render game
		viewport.center(player);
		viewport.refresh();
	}
}

int main() {
	// Initialize screen using ncurses ////////////////////////
	Screen scr;

	// print a string on screen
	printw("Thanks for playing.\nPress any key to continue.\nPress q to quit.");

	// starting key press
	int ch = getch();

	// create initial window
	Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

	// create subwindow of game map
	Frame viewport(game_map, scr.height(), scr.width(), 0, 0);



	// Initialize game objects and map /////////////////////
	// create player actor
	Actor player('@', game_map.height()/2, game_map.width()/2);

	// make map
	game_map.gen_Perlin(237);

	// enter game loop
	game_loop(game_map, viewport, player, ch);

	return 0;
}