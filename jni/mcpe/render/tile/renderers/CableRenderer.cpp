#include "CableRenderer.h"

void CableRenderer::render(const TilePos& pos, Tile* tile, TileTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	TileSource* ts = tess->region;
	
	bool insulated = ts->getTileAndData(x, y, z).data == 1;
	
	FullTile frontt = ts->getTileAndData(x + 1, y, z);
	FullTile backt = ts->getTileAndData(x - 1, y, z);
	FullTile leftt = ts->getTileAndData(x, y, z + 1);
	FullTile rightt = ts->getTileAndData(x, y, z - 1);
	FullTile bottomt = ts->getTileAndData(x, y - 1, z);
	FullTile topt = ts->getTileAndData(x, y + 1, z);
	
	bool front = frontt.id == tile->id;
	bool back = backt.id == tile->id;
	bool left = leftt.id == tile->id;
	bool right = rightt.id == tile->id;
	bool bottom = bottomt.id == tile->id;
	bool top = topt.id == tile->id;
	
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	
	tess->setRenderBounds(0.4, 0.4, 0.4, 0.6, 0.6, 0.6);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	if(insulated) {
		tess->setRenderBounds(0.35, 0.35, 0.35, 0.65, 0.65, 0.65);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(front) {
		tess->setRenderBounds(0.6, 0.4, 0.4, 1, 0.6, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(back) {
		tess->setRenderBounds(0, 0.4, 0.4, 0.4, 0.6, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(left) {
		tess->setRenderBounds(0.4, 0.4, 0.6, 0.6, 0.6, 1);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(right) {
		if(insulated) {
			if(rightt.data == 1) {
				tess->setRenderBounds(0.35, 0.35, 0, 0.65, 0.65, 0.4);
				tess->tessellateBlockInWorld(tile, {x, y, z});
			} else {
				tess->setRenderBounds(0.35, 0.35, 0.1, 0.65, 0.65, 0.4);
				tess->tessellateBlockInWorld(tile, {x, y, z});
			}
		}
		tess->setRenderBounds(0.4, 0.4, 0, 0.6, 0.6, 0.4);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(bottom) {
		if(insulated) {
			if(bottomt.data == 1) {
				tess->setRenderBounds(0.35, 0.1, 0.35, 0.65, 0.4, 0.65);
				tess->tessellateBlockInWorld(tile, {x, y, z});
			}
		}
		tess->setRenderBounds(0.4, 0, 0.4, 0.6, 0.4, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(top) {
		if(insulated) {
			tess->setRenderBounds(0.35, 0.6, 0.35, 0.65, 0.9, 0.65);
			tess->tessellateBlockInWorld(tile, {x, y, z});
		}
		tess->setRenderBounds(0.4, 0.6, 0.4, 0.6, 1, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	tess->useForcedUV = false;
}
