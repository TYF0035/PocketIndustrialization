#pragma once

#include "Material.h"
#include "FurnaceTile.h"

class GeneratorTile: public Tile {
public:
	static int _id;
	static GeneratorTile* tileGenerator;
	
public:
	GeneratorTile(int);
};
