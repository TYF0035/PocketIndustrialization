#pragma once

#include "Tile.h"
#include <mcpe/level/TileSource.h>
#include <mcpe/item/TileItem.h>
#include <mcpe/level/TileSource.h>
#include <mcpe/item/CopperCableItem.h>
#include <mcpe/item/InsulatedCopperCableItem.h>
#include <string>

class CopperCableTile: public Tile {
public:
	static int _id;
	static CopperCableTile* tileCopperCable;
	
public:
	CopperCableTile(int id);
	const TextureUVCoordinateSet& getTexture(signed char, int);
	AABB const& getShape(TileSource*, int, int, int, AABB&, bool);
	void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB, std::allocator<AABB>>&);
	bool isObstructingChests(TileSource*, int, int, int);
	int getResource(int, Random*);
	
public:
	TextureUVCoordinateSet secondary_tex;
};
