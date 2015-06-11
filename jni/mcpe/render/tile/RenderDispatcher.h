#pragma once

#include "BlockRenderer.h"

#include "mcpe/tile/Tile.h"
#include "mcpe/level/TileSource.h"
#include "TileTessellator.h"
#include "mcpe/level/TilePos.h"

#include <map>

class RenderDispatcher {
public:
	static std::map<int, BlockRenderer*> rendererMap;
	static void registerRenderer(int, BlockRenderer*);
	static bool dispatch(int, const TilePos&, Tile*, TileTessellator*);
};
