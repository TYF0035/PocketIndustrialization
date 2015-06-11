#include "GeneratorTile.h"

int GeneratorTile::_id = 176;
GeneratorTile* GeneratorTile::tileGenerator = NULL;

GeneratorTile::GeneratorTile(int id): Tile(id, &Material::stone) {
	tex = getTextureUVCoordinateSet("generator", 0);
	
	init();
	setNameId("generator");
	setCategory(2);
	new TileItem(id - 256);
}
