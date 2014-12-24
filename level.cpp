#include <iostream>
#include <fstream>
#include "level.h"
Level::Level(std::string file) {
	std::cout << "Reading from" << file << std::endl;
	level_file_stream.exceptions ( ifstream::failbit | ifstream::badbit );
	level_file_stream.open(file, std::ifstream::in);
}
Level::~Level() {
	level_file_stream.close();
}
