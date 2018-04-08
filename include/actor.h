#ifndef ACTOR_H_327859
#define ACTOR_H_327859

#include <string>
#include <textconsole.h>

#define MAXHEALTH	20
#define MAXHUNGER	100

#define UNUSEDCHAR		'0'

#define NORMALDAMAGE	2
#define WEAKDAMAGE		4
#define RESISTDAMAGE	1

class Actor {
private:
	// object/visual information
	int _row, _col;
	char _symbol;
	std::string _description;

	// state information
	bool _alive;
	int _health, _hunger;
	char _resistance, _weakness; 
	
	// player only?
	// maybe when an enemy with a key is killed, it drops the key?
	int _smallkeys;

public:
	Actor();
	Actor(char, int, int, std::string desc="Basic Actor",
		char resist=UNUSEDCHAR, char weak=UNUSEDCHAR,
		int numkeys=0);

	void moveto(int, int);

	void incHunger(int);
	void decHunger(int);
	void incHealth(int);
	void decHealth(int);

	void damage(char);

	int row() const;
	int col() const;
	char symbol() const;
	std::string description() const;
	bool alive() const;
	int health() const;
	int hunger() const;
	int smallkeys() const;
};

#endif