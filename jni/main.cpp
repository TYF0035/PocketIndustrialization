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
#include <mcpe/locale/I18n.h>

#include <mcpe/item/CopperCableItem.h>

#include <mcpe/tile/GeneratorTile.h>
#include <mcpe/tile/TankTile.h>
#include <mcpe/tile/CopperCableTile.h>

#include <mcpe/render/tile/renderers/TankRenderer.h>
#include <mcpe/render/tile/renderers/CableRenderer.h>

#include <mcpe/app/SharedConstants.h>

#define LOG_TAG "PocketIndustrialization"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

//Rendering Code
static void (*_TileTessellator$tessellateInWorld)(TileTessellator*, Tile*, const TilePos&, bool);
static void TileTessellator$tessellateInWorld(TileTessellator* self, Tile* tile, const TilePos& pos, bool b) {
	if(!RenderDispatcher::dispatch(tile->id, pos, tile, self))
		_TileTessellator$tessellateInWorld(self, tile, pos, b);
}

//Where The Blocks Get There Renderers
void initRenderers() {	
	RenderDispatcher::registerRenderer(TankTile::_id, new TankRenderer());
	RenderDispatcher::registerRenderer(CopperCableTile::_id, new CableRenderer());
}

//Where The Tiles Get Added
static void (*_Tile$initTiles)();
static void Tile$initTiles() {
	_Tile$initTiles();    
	LOGI("Adding blocks");
	GeneratorTile::tileGenerator = new GeneratorTile(GeneratorTile::_id);
	TankTile::tileTank = new TankTile(TankTile::_id);
	CopperCableTile::tileCopperCable = new CopperCableTile(CopperCableTile::_id);
	LOGI("Blocks added");

	initRenderers();
}

//Where The Items Get Added
static void (*_Item$initItems)();
static void Item$initItems() {
	LOGI("Adding items");
	CopperCableItem::itemCopperCable = new CopperCableItem(CopperCableItem::_id);
	LOGI("Items added");

	_Item$initItems();
}

//Adds The Blocks To The Creative Inventory
static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	LOGI("Adding creative items");
	Item::addCreativeItem(GeneratorTile::tileGenerator, 0);
	Item::addCreativeItem(TankTile::tileTank, 0);
	Item::addCreativeItem(CopperCableTile::tileCopperCable, 0);
	Item::addCreativeItem(CopperCableItem::itemCopperCable, 0);
	LOGI("Creative items added");
}

static std::string (*_I18n$get)(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
static std::string I18n$get(std::string const& key, std::vector<std::string, std::allocator<std::string>> const& a) {

	if(key == "item.copperCable.name") return "Copper Cable";
	if(key == "tile.tank.name") return "Tank";
	if(key == "tile.generator.name") return "Generator";
	
	return _I18n$get(key, a);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, (void**) &_TileTessellator$tessellateInWorld);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

	return JNI_VERSION_1_2;
}
