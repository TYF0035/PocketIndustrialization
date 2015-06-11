#include "CopperCableItem.h"

int CopperCableItem::_id = 2000;
CopperCableItem* CopperCableItem::itemCopperCable = NULL;

CopperCableItem::CopperCableItem(int id) : Item(id - 256) {
	setNameID("copperCable");
	setIcon("apple", 0); //setting it to copper_cable crashes the game; but why?
	setCategory(2);
};

bool CopperCableItem::useOn(ItemInstance *i, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	i->count++;
};
