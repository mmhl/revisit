#ifndef __LEVEL__H__
#define __LEVEL__H__
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
using namespace std;
enum class Tile {
	WALL,
	PLAYER,
	EMPTY,
	NPC
};
typedef vector<Tile> tiles_row;
class Level {
public:
	Level(std::string file);
	virtual ~Level();
private:
	vector<tiles_row> level_tiles;
	tiles_row read_next_row();
	ifstream level_file_stream;
};
#endif 
