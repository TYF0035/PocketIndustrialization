#pragma once

#include "Tile.h"
#include <mcpe/level/TileSource.h>
#include <mcpe/item/TileItem.h>
#include <mcpe/level/TileSource.h>
#include <string>

class CopperCableTile: public Tile {
public:
	static int _id;
	static CopperCableTile* tileCopperCable;
	
public:
	CopperCableTile(int id);
	const TextureUVCoordinateSet& getTexture(signed char, int);
	bool isObstructingChests(TileSource*, int, int, int);
	
public:
	TextureUVCoordinateSet secondary_tex;
};
