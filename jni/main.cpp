#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include <mcpe/tile/Tile.h>
#include <mcpe/item/Item.h>
#include <mcpe/render/tile/RenderDispatcher.h>
#include <mcpe/render/tile/TileTessellator.h>
#include <mcpe/gui/StartMenuScreen.h>

#include <mcpe/item/CopperCableItem.h>

#include <mcpe/tile/GeneratorTile.h>
#include <mcpe/tile/TankTile.h>
#include <mcpe/tile/CopperCableTile.h>

#include <mcpe/render/tile/renderers/TankRenderer.h>
#include <mcpe/render/tile/renderers/CableRenderer.h>

#include <mcpe/app/SharedConstants.h>

#define LOG_TAG "PocketIndustrialization"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*TileTessellator_tessellateInWorld_real)(TileTessellator*, Tile*, const TilePos&, bool);
static void TileTessellator_tessellateInWorld_hook(TileTessellator* self, Tile* tile, const TilePos& pos, bool sth) {
	if(!RenderDispatcher::dispatch(tile->id, pos, tile, self))
		TileTessellator_tessellateInWorld_real(self, tile, pos, sth);
}

static void setupRenderers() {
	RenderDispatcher::registerRenderer(TankTile::_id, new TankRenderer());
	RenderDispatcher::registerRenderer(CopperCableTile::_id, new CableRenderer());
}

static void (*Tile_initTiles_real)();
static void Tile_initTiles_hook() {
	Tile_initTiles_real();
	LOGI("Adding blocks");
	GeneratorTile::tileGenerator = new GeneratorTile(GeneratorTile::_id);
	TankTile::tileTank = new TankTile(TankTile::_id);
	CopperCableTile::tileCopperCable = new CopperCableTile(CopperCableTile::_id);
	LOGI("Blocks added");
}

static void (*Item_initItems_real)();
static void Item_initItems_hook() {
	Item_initItems_real();
	LOGI("Adding items");
	CopperCableItem::itemCopperCable = new CopperCableItem(CopperCableItem::_id);
	LOGI("Items added");
}

static void (*Item_initCreativeItems_real)();
static void Item_initCreativeItems_hook() {
	Item_initCreativeItems_real();
	LOGI("Adding creative items");
	Item::addCreativeItem(GeneratorTile::tileGenerator, 0);
	Item::addCreativeItem(TankTile::tileTank, 0);
	Item::addCreativeItem(CopperCableTile::tileCopperCable, 0);
	LOGI("Creative items added");
}

static bool (*TileTessellator_canRender_real)(int);
static bool TileTessellator_canRender_hook(int renderType) {
	//Returning true makes Tanks invisible in hand
	return true;
	return TileTessellator_canRender_real(renderType);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	setupRenderers();
	
	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator_tessellateInWorld_hook, (void**) &TileTessellator_tessellateInWorld_real);
	MSHookFunction((void*) &Item::initItems, (void*) &Item_initItems_hook, (void**) &Item_initItems_real);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile_initTiles_hook, (void**) &Tile_initTiles_real);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item_initCreativeItems_hook, (void**) &Item_initCreativeItems_real);
	MSHookFunction((void*) &TileTessellator::canRender, (void*) &TileTessellator_canRender_hook, (void**) &TileTessellator_canRender_real);
	
	return JNI_VERSION_1_2;
}
