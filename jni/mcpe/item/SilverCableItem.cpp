#include "SilverCableItem.h"

int SilverCableItem::_id = 2010;
SilverCableItem* SilverCableItem::itemSilverCable = NULL;

SilverCableItem::SilverCableItem(int id) : Item(id - 256) {
	setNameID("silverCable");
	setIcon("copper_cable", 0); //Temporary
	setCategory(2);
};

bool SilverCableItem::useOn(ItemInstance *i, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	i->count++;
};
