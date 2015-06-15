#pragma once

#include "Tile.h"
#include <mcpe/level/TileSource.h>
#include <mcpe/item/TileItem.h>
#include <mcpe/level/TileSource.h>
#include <string>

class SilverCableTile: public Tile {
public:
	static int _id;
	static SilverCableTile* tileSilverCable;
	
public:
	SilverCableTile(int id);
	const TextureUVCoordinateSet& getTexture(signed char, int);
	bool isObstructingChests(TileSource*, int, int, int);
	
public:
	TextureUVCoordinateSet secondary_tex;
};
