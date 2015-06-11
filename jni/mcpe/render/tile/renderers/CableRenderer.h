#pragma once

#include <mcpe/tile/Tile.h>
#include "../BlockRenderer.h"
#include "../TileTessellator.h"
#include <mcpe/CommonTypes.h>
#include <mcpe/level/TileSource.h>

class CableRenderer: public BlockRenderer {
public:
	void render(const TilePos&, Tile*, TileTessellator*);
};
