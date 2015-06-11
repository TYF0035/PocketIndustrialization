#include "Tile.h"
#include "Material.h"
#include "CopperCableTile.h"

CopperCableTile* CopperCableTile::tileCopperCable = NULL;
int CopperCableTile::_id = 179;

CopperCableTile::CopperCableTile(int id): Tile(id, &Material::glass) {
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	
	init();
	tex = getTextureUVCoordinateSet("gold_block", 0);
	secondary_tex = getTextureUVCoordinateSet("wool", 15);
	
	renderType = 100; //Make it render in hand
	
	setNameId("copperCable");
	setCategory(2);
	
	Tile::tiles[id] = this;
	new TileItem(id - 256);
}

const TextureUVCoordinateSet& CopperCableTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

bool CopperCableTile::isObstructingChests(TileSource*, int, int, int) {
	return false;
}

