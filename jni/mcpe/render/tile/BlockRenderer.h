#pragma once

#include "mcpe/level/TileSource.h"
#include "mcpe/render/tile/TileTessellator.h"
#include "mcpe/level/TilePos.h"

class BlockRenderer {
public:
	virtual void render(const TilePos&, Tile*, TileTessellator*) = 0;

	void setRotatedBounds(TileTessellator*, int, float, float, float, float, float, float);
};
