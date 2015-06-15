#include "Tile.h"
#include "Material.h"
#include "SilverCableTile.h"

SilverCableTile* SilverCableTile::tileSilverCable = NULL;
int SilverCableTile::_id = 180;

SilverCableTile::SilverCableTile(int id): Tile(id, &Material::glass) {
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	
	init();
	tex = getTextureUVCoordinateSet("iron_block", 0);
	secondary_tex = getTextureUVCoordinateSet("wool", 15);
	
	renderType = 100; //Make it render in hand
	
	setNameId("silverCable");
	setCategory(2);
	
	Tile::tiles[id] = this;
	new TileItem(id - 256);
}

const TextureUVCoordinateSet& SilverCableTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

bool SilverCableTile::isObstructingChests(TileSource*, int, int, int) {
	return false;
}
