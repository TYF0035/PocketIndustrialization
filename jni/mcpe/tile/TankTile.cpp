#include "TankTile.h"

TankTile* TankTile::tileTank = NULL;
int TankTile::_id = 178;

TankTile::TankTile(int id): Tile(id, &Material::glass) {
	tex = getTextureUVCoordinateSet("tank_side", 0);
	secondary_tex = getTextureUVCoordinateSet("tank_top", 0);
	terciary_tex = getTextureUVCoordinateSet("still_water", 0);
	
	setNameId("tank");
	setCategory(2);
	setShape(0.125, 0, 0.125, 0.875, 1, 0.875);
	init();
	
	//renderType = 1; //Make it render in hand
	
	renderPass = Tile::mobSpawner->renderPass;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}

const TextureUVCoordinateSet& TankTile::getTexture(signed char side, int data) {
	return side == 0 || side == 1 ? secondary_tex : (side == 6 ? terciary_tex : tex);
}

bool TankTile::isObstructingChests(TileSource*, int, int, int) {
	return false;
}
