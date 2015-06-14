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
	
	setCategory(2);
	
	Tile::tiles[id] = this;
	new TileItem(id - 256);
}

AABB const& CopperCableTile::getShape(TileSource* ts, int x, int y, int z, AABB&, bool) {
	float x1 = 0.4, y1 = 0.4, z1 = 0.4, x2 = 0.6, y2 = 0.6, z2 = 0.6;
	
	if(ts->getTile(x - 1, y, z) == CopperCableTile::_id) x1 = 0;
	if(ts->getTile(x, y - 1, z) == CopperCableTile::_id) y1 = 0;
	if(ts->getTile(x, y, z - 1) == CopperCableTile::_id) z1 = 0;
	if(ts->getTile(x + 1, y, z) == CopperCableTile::_id) x2 = 1;
	if(ts->getTile(x, y + 1, z) == CopperCableTile::_id) y2 = 1;
	if(ts->getTile(x, y, z + 1) == CopperCableTile::_id) z2 = 1;
	
	return AABB(x1, y1, z1, x2, y2, z2);
}

void CopperCableTile::addAABBs(TileSource* ts, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	float x1 = 0.4, y1 = 0.4, z1 = 0.4, x2 = 0.6, y2 = 0.6, z2 = 0.6;
	
	if(ts->getTile(x - 1, y, z) == CopperCableTile::_id) x1 = 0;
	if(ts->getTile(x, y - 1, z) == CopperCableTile::_id) y1 = 0;
	if(ts->getTile(x, y, z - 1) == CopperCableTile::_id) z1 = 0;
	if(ts->getTile(x + 1, y, z) == CopperCableTile::_id) x2 = 1;
	if(ts->getTile(x, y + 1, z) == CopperCableTile::_id) y2 = 1;
	if(ts->getTile(x, y, z + 1) == CopperCableTile::_id) z2 = 1;
	
	addAABB(AABB(x1, y1, z1, x2, y2, z2).move(x, y, z), posAABB, pool);
}

const TextureUVCoordinateSet& CopperCableTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

bool CopperCableTile::isObstructingChests(TileSource*, int, int, int) {
	return false;
}

int CopperCableTile::getResource(int data, Random*) {
	return data == 0 ? CopperCableItem::_id : InsulatedCopperCableItem::_id;
}
